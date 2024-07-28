import pycuda.autoinit
import pycuda.driver as cuda
from pycuda.compiler import SourceModule
import numpy as np

# rango de los ejes x e y
x_max = 1
x_min = -2
y_max = 1.5
y_min = -1.5

# nombre del archivo
file = "mandel_py.bmp"

# tamanio y el numero de iteraciones
width = 6000
height = 6000
W_x_H = width * height
max_iter = 500

h_x_step = (x_max - x_min) / width
h_y_step = (y_max - y_min) / height

def initVar():

    padding = 4 - (width * 3) % 4
    if (padding == 4):
        padding = 0
    
    # datos de la cabecera
    size = 54 + ((width * 3) + padding) * height
    reserved1 = 0
    reserved2 = 0
    offset = 54
    header_size = 40
    planes = 1
    bitsperpixel = 24
    compression = 0
    image_size = ((width * 3) + padding) * height
    x_resolution = 0
    y_resolution = 0
    used_colors = 0
    important_colors = 0

    global header, output

    header = b'\x42\x4D' + \
             size.to_bytes(4, 'little') + \
             reserved1.to_bytes(2, 'little') + \
             reserved2.to_bytes(2, 'little') + \
             offset.to_bytes(4, 'little') + \
             header_size.to_bytes(4, 'little') + \
             width.to_bytes(4, 'little') + \
             height.to_bytes(4, 'little') + \
             planes.to_bytes(2, 'little') + \
             bitsperpixel.to_bytes(2, 'little') + \
             compression.to_bytes(4, 'little') + \
             image_size.to_bytes(4, 'little') + \
             x_resolution.to_bytes(4, 'little') + \
             y_resolution.to_bytes(4, 'little') + \
             used_colors.to_bytes(4, 'little') + \
             important_colors.to_bytes(4, 'little') 
    
    # inicializacion de los pixeles
    output = np.empty(image_size, dtype=np.uint8)

# guardado de la imagen
def saveBMP():
    with open(file, "wb") as fp:
        fp.write(header)
        fp.write(output)

# compila el codigo CUDA
mod = SourceModule("""
    __constant__ int dev_iter;
    __constant__ double dev_x_min;
    __constant__ double dev_y_min;
    __constant__ double dev_x_step;
    __constant__ double dev_y_step;
    __constant__ int dev_W_x_H;
    __constant__ int dev_width;
    __constant__ int dev_row_size;
                   
    __device__ void setPixelColor(int iter, double re2, double im2, char *r, char *g, char *b) {
        
        // escala de grises que es menos exigente
        int gray = (char)(255 * iter / dev_iter);
        *r = gray;
        *g = gray;
        *b = gray;

        /*
        double mu = iter + 1 - log(log(sqrt(re2 + im2))) / log(2.0);
        double log_zn = log(re2 + im2) / 2.0;
        double nu = log(log_zn / log(2.0)) / log(2.0);
        double iter_smooth = iter + 1 - nu;

        double t = iter_smooth / 256.0;
        double t2 = t * t;
        double t3 = t2 * t;
        double t4 = t3 * t;
        double t5 = t4 * t;

        *r = (int)(9 * (1 - t5) * t4 * 255);
        *g = (int)(15 * (1 - t5) * t3 * t2 * 255);
        *b = (int)(8.5 * (1 - t5) * t2 * t * 255);
        */
    }
                   
    // calcula las itereaciones de mandelbrot -->  Z_{n+1} = Z_n^2 + C  
    __device__ void pixelIter(int i, int j, char *r, char *g, char *b){
    
        int iteration = 0;
        double c_re = dev_x_min + dev_x_step/2 + j * dev_x_step;
        double c_im = dev_y_min + dev_y_step/2 + i * dev_y_step;
    
        double zn_re = 0.0;
        double zn_im = 0.0;
        double tmp_re;

        double re2 = 0;
        double im2 = 0; 
        
        while ((re2 + im2 < 4) && (iteration < dev_iter)){
            // Z_{n+1} = Z_n^2 + C => z_n+1_R = z_n_R^2 - z_n_I^2 + c_R
            //                        z_n+1_I = 2 * z_n_R * z_n_I + c_I
            tmp_re = re2 - im2 + c_re;
            zn_im = 2 * zn_re * zn_im + c_im;
            zn_re = tmp_re;

            //valores para la siguiente iteracion
            re2 = zn_re * zn_re;
            im2 = zn_im * zn_im;
            iteration++;
        }

        setPixelColor(iteration, re2, im2, r, g, b);
    }
                   
    __global__ void mandelbrot(char *dev_img, int width, int height, double dev_x_min, double dev_x_max, double dev_y_min, double dev_y_max, int max_iter) {
        int offset = gridDim.x * blockDim.x * threadIdx.y + blockIdx.x * blockDim.x + threadIdx.x;
        int i = offset / dev_width;
        int j = offset - i * dev_width;

        // comprueba que el pixel esta dentro de la imagen
        if (offset < dev_W_x_H){
            offset = dev_row_size * i + 3 * j; // offset in the image array
            
            pixelIter(i, j, &dev_img[offset + 2], &dev_img[offset + 1], &dev_img[offset]);

        }
    }
""")

if __name__ == "__main__":
    initVar()

    # obtener una referencia al kernel CUDA
    mandelbrot_kernel = mod.get_function("mandelbrot")

    # punteros a varibales del device
    dev_iter_pointer = mod.get_global("dev_iter")[0]
    cuda.memcpy_htod(dev_iter_pointer, np.int32(max_iter))
    dev_x_min_pointer = mod.get_global("dev_x_min")[0]
    cuda.memcpy_htod(dev_x_min_pointer, np.float64(x_min))
    dev_y_min_pointer = mod.get_global("dev_y_min")[0]
    cuda.memcpy_htod(dev_y_min_pointer, np.float64(y_min))
    dev_x_step_pointer = mod.get_global("dev_x_step")[0]
    cuda.memcpy_htod(dev_x_step_pointer, np.float64(h_x_step))
    dev_y_step_pointer = mod.get_global("dev_y_step")[0]
    cuda.memcpy_htod(dev_y_step_pointer, np.float64(h_y_step))
    dev_W_x_H_pointer = mod.get_global("dev_W_x_H")[0]
    cuda.memcpy_htod(dev_W_x_H_pointer, np.int32(width * height))
    dev_width_pointer = mod.get_global("dev_width")[0]
    cuda.memcpy_htod(dev_width_pointer, np.int32(width))
    dev_row_size_pointer = mod.get_global("dev_row_size")[0]
    cuda.memcpy_htod(dev_row_size_pointer, np.int32(width * 3))

    # llama al kernel CUDA
    block_size = (256, 1, 1)
    temp_block_size = (block_size[0] * block_size[1])
    grid_size = ((W_x_H // temp_block_size) + (1 if W_x_H % temp_block_size != 0 else 0), 1, 1)
    mandelbrot_kernel(cuda.Out(output), np.int32(width), np.int32(height), np.float64(x_min), np.float64(x_max), np.float64(y_min), np.float64(y_max), np.int32(max_iter), block=block_size, grid=grid_size)

    saveBMP()

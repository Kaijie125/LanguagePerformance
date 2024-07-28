
#define BLOCK_SIZE_X 256
#define BLOCK_SIZE_Y 1

__constant__ int dev_iter;
__constant__ double dev_x_min;
__constant__ double dev_y_min;
__constant__ double dev_x_step;
__constant__ double dev_y_step;
__constant__ int dev_W_x_H;
__constant__ int dev_width;
__constant__ int dev_row_size;

// colorea el pixel en funcion del numero de iteraciones
__device__ void setPixelColor(int iter, double re2, double im2, char *r, char *g, char *b){
    
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
    
    // pixel a coordenadas complejas, C de la formula 
    //donde se suma medio "step" para estar en el centro del pixel
    double c_re = dev_x_min + dev_x_step/2 + j * dev_x_step;
    double c_im = dev_y_min + dev_y_step/2 + i * dev_y_step;
    //Z_0 = 0
    double zn_re = 0;
    double zn_im = 0;
    //temporal
    double tmp_re;
    // valor de Z_n^2 inicialmente es 0 + 0i
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


// funcion principal de mandelbrot
__global__ void mandelbrot(char *dev_img){
    // calcula el offset del pixel mediante el indice del bloque y el indice del thread
    int offset = gridDim.x * blockDim.x * threadIdx.y + blockIdx.x * blockDim.x + threadIdx.x;
    int i = offset / dev_width;
    int j = offset - i * dev_width;

    // comprueba que el pixel esta dentro de la imagen
    if (offset < dev_W_x_H){
        offset = dev_row_size * i + 3 * j; // offset in the image array
        
        pixelIter(i, j, &dev_img[offset + 2], &dev_img[offset + 1], &dev_img[offset]);

    }
}

void kernel_mandelbrot(char *hst_img, int img_size, int iter, double x_min, double y_min, double x_step, double y_step, int W_x_H, int width, int row_size){
    // puntero a la imagen en el device
    char *dev_img;

    // dimensiones de los bloques y de la grid
    dim3 block_size;
    dim3 grid_size;
    block_size.x = BLOCK_SIZE_X;
    block_size.y = BLOCK_SIZE_Y;
    grid_size.x = W_x_H / (block_size.x * block_size.y) + (W_x_H % (block_size.x * block_size.y) == 0? 0 : 1);

    // reserva memoria en el device
    cudaMalloc((void**)&dev_img, img_size);
    cudaMemset(dev_img, 0, img_size);

    // copia los parametros al device
    cudaMemcpyToSymbol(dev_iter, &iter, sizeof(int));
    cudaMemcpyToSymbol(dev_x_min, &x_min, sizeof(double));
    cudaMemcpyToSymbol(dev_y_min, &y_min, sizeof(double));
    cudaMemcpyToSymbol(dev_x_step, &x_step, sizeof(double));
    cudaMemcpyToSymbol(dev_y_step, &y_step, sizeof(double));
    cudaMemcpyToSymbol(dev_W_x_H, &W_x_H, sizeof(int));
    cudaMemcpyToSymbol(dev_width, &width, sizeof(int));
    cudaMemcpyToSymbol(dev_row_size, &row_size, sizeof(int));

    // ejecuta el kernel
    mandelbrot<<<grid_size, block_size>>>(dev_img);
    // copia el resultado al host
    cudaMemcpy(hst_img, dev_img, img_size, cudaMemcpyDeviceToHost);
    // libera memoria del device
    cudaFree(dev_img);
}

// wrapper para llamar al kernel desde C
extern "C" void kernel_wrapper(char *hst_img, int img_size, int iter, double x_min, double y_min, double x_step, double y_step, int W_x_H, int width, int row_size){
    kernel_mandelbrot(hst_img, img_size, iter, x_min, y_min, x_step, y_step, W_x_H, width, row_size);
}
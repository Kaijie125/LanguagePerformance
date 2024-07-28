import threading

N_THREADS = 4

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
iter = 500

# conversion pixeles a coordenada x e y; incremento entre pixeles
x_step = (x_max - x_min) / width
y_step = (y_max - y_min) / height

def initVar():

    padding = 4 - (width * 3) % 4
    if (padding == 4):
        padding = 0

    global row_size 
    row_size = width * 3 + padding
    
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

    global header, img_data

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
    img_data = bytearray(image_size)
    # img_data = [0] * image_size
    # img_data = = [0 for _ in range(n)]

# guardado de la imagen
def saveBMP():
    with open(file, "wb") as fp:
        fp.write(header)
        fp.write(bytes(img_data))

# color de los pixeles
def setPixelColor(iteration, re2, im2, offset):
    # Escala de grises
    gray = int(255 * iteration / iter)
    img_data[offset + 2] = gray # R
    img_data[offset + 1] = gray # G
    img_data[offset] = gray # B

# calculo de la iteracion
def pixelIter(i, j, offset):
    iteration = 0
    c_re = x_min + x_step / 2 + j * x_step
    c_im = y_min + y_step / 2 + i * y_step
    zn_re, zn_im = 0, 0
    re2, im2 = 0, 0

    while (re2 + im2 < 4) and (iteration < iter):
        tmp_re = re2 - im2 + c_re
        zn_im = 2 * zn_re * zn_im + c_im
        zn_re = tmp_re
        re2 = zn_re * zn_re
        im2 = zn_im * zn_im
        iteration += 1

    setPixelColor(iteration, re2, im2, offset)

# funcion principal de mandelbrot
def mandelbrot(arg_i, arg_j, arg_end_height, arg_end_width):
    for i in range(arg_i, arg_end_height):
        for j in range(arg_j, arg_end_width):
            offset = row_size * i + 3 * j
            pixelIter(i, j, offset)

# funcion de los hilos
def paralelInit():

    threads = []
    for i in range(N_THREADS):
        arg_i = i * (height // N_THREADS)
        arg_j = 0
        arg_end_height = (i + 1) * (height // N_THREADS)
        arg_end_width = width
        t = threading.Thread(target=mandelbrot, args=(arg_i, arg_j, arg_end_height, arg_end_width))
        threads.append(t)
        t.start()

    for thread in threads:
        thread.join()

if __name__ == "__main__":
    initVar()
    paralelInit()
    saveBMP()

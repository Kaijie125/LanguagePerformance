#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <string.h>

#define N_THREADS 4

// structura de la cabecera de la imagen
#pragma pack(push, 1)

typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
    uint32_t header_size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitsperpixel;
    uint32_t compression;
    uint32_t image_size;
    int32_t x_resolution;
    int32_t y_resolution;
    uint32_t used_colors;
    uint32_t important_colors;
} BMPHeader;

#pragma pack(pop)

BMPHeader header;

// rango de los ejes x e y
double x_max = 1;
double x_min = -2;
double y_max = 1.5;
double y_min = -1.5;

// nombre de la imagen
char *file = "mandel_c.bmp";

// tamanio y el numero de iteraciones
int width = 6000;
int height = 6000;
int iter = 500;

// padding, tamanio de la fila y del imagen
int padding;
int row_size;
int img_size;

// datos de la imagen; pixeles
char *img_data;

// conversion pixeles a coordenada x e y; incremento entre pixeles
double x_step; 
double y_step;

// estructura de los argumentos de los hilos
typedef struct {
    int i;
    int j;
    int end_height;
    int end_width;
} threadArgs;

// inicializacion de las variables
void initVar(){
    // desplazamiento de los ejes
    x_step = (x_max - x_min) / width;
    y_step = (y_max - y_min) / height;

    // calculo del padding padding = (4 - (width * 3) % 4) % 4;
    padding = 4 - (width * 3) % 4;
    if (padding == 4) {
        padding = 0;
    }

    // calculo del tamanio de la fila y del imagen
    row_size = width * 3 + padding;
    img_size = row_size * height;

    // datos de la cabezera
    header.type = 0x4D42;
    header.size = sizeof(BMPHeader) + img_size;
    header.reserved1 = 0;
    header.reserved2 = 0,
    header.offset = sizeof(BMPHeader);
    header.header_size = 40;
    header.width = width;
    header.height = height;
    header.planes = 1;
    header.bitsperpixel = 24;
    header.compression = 0;
    header.image_size = img_size;
    header.x_resolution = 0;
    header.y_resolution = 0;
    header.used_colors = 0;
    header.important_colors = 0;

    // inicializo los pixeles
    img_data = (char *) calloc(img_size, sizeof(char));
}

// guradado de la imagen
void saveBMP(){
    FILE *fp = fopen(file, "wb");
    if (!fp) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    
    fwrite(&header, sizeof(BMPHeader), 1, fp);
    fwrite(img_data, img_size, 1, fp);
    fclose(fp);
}

// color de cada pixel
void setPixelColor(int iteration, double re2, double im2, char *r, char *g, char *b) {
    // Escala de grises
    int gray = (char)(255 * iteration / iter);
    *r = gray;
    *g = gray;
    *b = gray;
}

// calculo de la iteracion de un pixel
void pixelIter(int i, int j, char *r, char *g, char *b) {
    int iteration = 0;
    double c_re = x_min + x_step/2 + j * x_step;
    double c_im = y_min + y_step/2 + i * y_step;
    double zn_re = 0;
    double zn_im = 0;
    double tmp_re;
    double re2 = 0;
    double im2 = 0;

    while ((re2 + im2 < 4) && (iteration < iter)) {
        tmp_re = re2 - im2 + c_re;
        zn_im = 2 * zn_re * zn_im + c_im;
        zn_re = tmp_re;
        re2 = zn_re * zn_re;
        im2 = zn_im * zn_im;
        iteration++;
    }

    setPixelColor(iteration, re2, im2, r, g, b);
}

// funcion principal de mandelbrot
void *mandelbrot(void *t_args) {
    int offset;
    threadArgs args;
    memcpy (&args, t_args, sizeof(threadArgs));
    for (int i = args.i; i < args.end_height; i++) {
        for (int j = args.j; j < args.end_width; j++) {
            offset = row_size * i + 3 * j;
            pixelIter(i, j, &img_data[offset + 2], &img_data[offset + 1], &img_data[offset]);
        }
    }
}

// funcion de los hilos
void paralelInit(){
    
    pthread_t threads[N_THREADS];
    threadArgs args[N_THREADS];
    for(int i = 0; i < N_THREADS; i++){
        args[i].i = i * (height / N_THREADS);
        args[i].j = 0;
        args[i].end_height = (i + 1) * (height / N_THREADS);
        args[i].end_width = width;
        pthread_create(&threads[i], NULL, mandelbrot, &args[i]);
    }
    
    for (int i = 0; i < N_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {

    initVar();

    paralelInit();

    saveBMP();

    free(img_data);

    return 0;
}

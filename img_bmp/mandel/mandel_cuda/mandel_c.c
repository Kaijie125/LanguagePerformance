#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

// cabecera de la imagen
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
char *hst_img;

// conversion pixeles a coordenada x e y; incremento entre pixeles
double h_x_step; 
double h_y_step;

// llamada al kernel donde se encuantra el el fichero .cu
void kernel_wrapper(char *hst_img, int img_size, int iter, double x_min, double y_min, double h_x_step, double h_y_step, int W_x_H, int width, int row_size);

// inicializacion de las variables
void initVar(){
    // desplazamiento de los ejes
    h_x_step = (x_max - x_min) / width;
    h_y_step = (y_max - y_min) / height;

    // calculo del padding
    // padding = (4 - (width * 3) % 4) % 4;
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

    // inicializo los pixeles, los valores seran copiados desde el gpu
    hst_img = (char *) malloc(img_size);
}

// guardar la imagen
void saveBMP(){
    FILE *fp = fopen(file, "wb");
    if (!fp) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    
    fwrite(&header, sizeof(BMPHeader), 1, fp);
    fwrite(hst_img, img_size, 1, fp);
    fclose(fp);
}

int main() {

    initVar();

    kernel_wrapper(hst_img, img_size, iter, x_min, y_min, h_x_step, h_y_step, width * height, width, row_size);

    saveBMP();

    free(hst_img);

    return 0;
}



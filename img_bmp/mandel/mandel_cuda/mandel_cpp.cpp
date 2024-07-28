#include <iostream>
#include <fstream>
#include <cstdint>

// estructura de la cabecera de la imagen
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
const char* file = "mandel_cpp.bmp";

// tamanio y el numero de iteraciones
int width = 6000;
int height = 6000;
int iter = 500;

// padding, tamanio de la fila y del imagen
int padding;
int row_size;
int img_size;

// datos de la imagen; pixeles
char* hst_img;

// conversión pixeles a coordenadas x e y; incremento entre pixeles
double h_x_step;
double h_y_step;

// declaracion de la funcion del kernel
void kernel_mandelbrot(char* hst_img, int img_size, int iter, double x_min, double y_min, double h_x_step, double h_y_step, int W_x_H, int width, int row_size);

void initVar() {
    // desplazamiento de los ejes
    h_x_step = (x_max - x_min) / width;
    h_y_step = (y_max - y_min) / height;

    // aclculo del padding
    padding = 4 - (width * 3) % 4;
    if (padding == 4) {
        padding = 0;
    }

    // calculo del tamanio de la fila y de la imagen
    row_size = width * 3 + padding;
    img_size = row_size * height;

    // datos de la cabecera
    header.type = 0x4D42;
    header.size = sizeof(BMPHeader) + img_size;
    header.reserved1 = 0;
    header.reserved2 = 0;
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

    // inicializo los pixeles, donde los valores seracopiado desde el gpu
    hst_img = new char[img_size];
}

// guarda la imagen en un archivo
void saveBMP() {
    std::ofstream fp(file, std::ios::out | std::ios::binary);
    if (!fp.is_open()) {
        std::cout << "Error al abrir el archivo." << std::endl;
        return;
    }

    fp.write(reinterpret_cast<char*>(&header), sizeof(BMPHeader));
    fp.write(hst_img, img_size);
    fp.close();
}

int main() {
    initVar();

    // uso de la funcion del kernel
    kernel_mandelbrot(hst_img, img_size, iter, x_min, y_min, h_x_step, h_y_step, width * height, width, row_size);

    saveBMP();

    delete[] hst_img;

    return 0;
}

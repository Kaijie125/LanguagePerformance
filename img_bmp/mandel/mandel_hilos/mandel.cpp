#include <iostream>
#include <fstream>
#include <cstdint>
#include <thread>

#define NUM_THREADS 4

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

// datos de la imagen
const char* file = "mandel_cpp.bmp";

int width = 6000;
int height = 6000;
int iter = 500;
// bytes de relleno
int padding;
int row_size;
int img_size;

// datos de la imagen; pixeles
char* hst_img;

// conversion pixeles a coordenadas x e y; incremento entre pixeles
double x_step;
double y_step;

// estructura para los argumentos de los hilos
typedef struct {
    int i;
    int j;
    int end_height;
    int end_width;
    int t_id;
} threadArgs;

void initVar() {
    // desplazamiento de los ejes
    x_step = (x_max - x_min) / width;
    y_step = (y_max - y_min) / height;

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

    // inicializo los pixeles
    hst_img = new char[img_size];
}

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

void setPixelColor(int iteration, double re2, double im2, char &r, char &g, char &b) {
    // Escala de grises
    int gray = static_cast<char>(255 * iteration / iter);
    r = gray;
    g = gray;
    b = gray;
}

void pixelIter(int i, int j, char &r, char &g, char &b) {
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

void mandelbrot(threadArgs args) {
    int offset;
    for (int i = args.i; i < args.end_height; i++) {
        for (int j = args.j; j < args.end_width; j++) {
            offset = row_size * i + 3 * j;
            pixelIter(i, j, hst_img[offset], hst_img[offset + 1], hst_img[offset + 2]);
        }
    }
}

void paralelInit() {
    std::thread threads[NUM_THREADS];
    threadArgs t_args[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        t_args[i].i = i * (height / NUM_THREADS);
        t_args[i].j = 0;
        t_args[i].end_height = (i + 1) * (height / NUM_THREADS);
        t_args[i].end_width = width;
        t_args[i].t_id = i;
        threads[i] = std::thread(mandelbrot, t_args[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        threads[i].join();
    }
}

int main() {
    initVar();

    paralelInit();
    
    saveBMP();

    delete[] hst_img;

    return 0;
}

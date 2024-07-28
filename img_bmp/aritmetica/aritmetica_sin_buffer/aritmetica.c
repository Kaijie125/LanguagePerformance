#include <stdio.h>
#include <stdint.h>

// alineamiento de memoria a 1 byte debido a los distintos dipos de datos
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

//alineamiento normal
#pragma pack(pop)

void createBMP(int width, int height) {
    
    char padding_byte = 0;
    // padding = (4 - (width * 3) % 4) % 4;
    uint32_t n_padding_byte = 4 - ((width * 3) % 4);
    if (n_padding_byte == 4){
        n_padding_byte = 0;
    }

    // datos de la cabecera
    BMPHeader header = {
        .type = 0x4D42, // 0x4D42 = MB, se almacena en formato little-endian
        .size = sizeof(BMPHeader) + ((width * 3) + n_padding_byte) * height,
        .reserved1 = 0,
        .reserved2 = 0,
        .offset = sizeof(BMPHeader),
        .header_size = 40,
        .width = width,
        .height = height,
        .planes = 1,
        .bitsperpixel = 24,
        .compression = 0,
        .image_size = ((width * 3) + n_padding_byte) * height,
        .x_resolution = 0,
        .y_resolution = 0,
        .used_colors = 0,
        .important_colors = 0
    };

    // apertura del archivo
    FILE* file = fopen("img_c.bmp", "wb");
    if (!file) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    // escritura de la cabecera en el archivo
    fwrite(&header, sizeof(BMPHeader), 1, file);

    // colores de la imagen
    char r, g, b;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            r = (char)((x / (float)width) * 255);
            g = (char)(((height - y) / (float)height) * 255);
            b = (char)((y / (float)height) * 255);

            fwrite(&b, sizeof(char), 1, file);
            fwrite(&g, sizeof(char), 1, file);
            fwrite(&r, sizeof(char), 1, file);

        }

        for (int z = 0; z < n_padding_byte; z++){
            fwrite(&padding_byte, sizeof(char), 1, file);
        }
    }
    fclose(file);
}

int main() {
    int width = 8000;
    int height = 8000;

    createBMP(width, height);
    return 0;
}
#include <iostream>
#include <fstream>

// alineamiento de la memoria
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

// alineamiento normal
#pragma pack(pop)

void createBMP(int width, int height) {

    char padding_byte = 0;
    // padding = (4 - (width * 3) % 4) % 4;
    uint32_t n_padding_byte = 4 - ((width * 3) % 4);
    if (n_padding_byte == 4){
        n_padding_byte = 0;
    }

    // datos de la cabezera
    BMPHeader header = {
        .type = 0x4D42,
        .size = static_cast<uint32_t>(sizeof(BMPHeader) + ((width * 3) + n_padding_byte) * height),
        .reserved1 = 0,
        .reserved2 = 0,
        .offset = static_cast<uint32_t>(sizeof(BMPHeader)),
        .header_size = 40,
        .width = width,
        .height = height,
        .planes = 1,
        .bitsperpixel = 24,
        .compression = 0,
        .image_size = static_cast<uint32_t>(((width * 3) + n_padding_byte) * height),
        .x_resolution = 0,
        .y_resolution = 0,
        .used_colors = 0,
        .important_colors = 0
    };

    // apertura del archivo
    std::ofstream file("img_cpp.bmp", std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Error al abrir el archivo." << std::endl;
        return;
    }

    // escritura de la cabezera
    file.write(reinterpret_cast<char*>(&header), sizeof(BMPHeader));

    // colores de la imagen
    char r, g, b;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            r = static_cast<char>((x / static_cast<float>(width)) * 255);
            g = static_cast<char>(((height - y) / static_cast<float>(height)) * 255);
            b = static_cast<char>((y / static_cast<float>(height)) * 255);

            file.write(reinterpret_cast<char*>(&b), sizeof(char));
            file.write(reinterpret_cast<char*>(&g), sizeof(char));
            file.write(reinterpret_cast<char*>(&r), sizeof(char));

        }

        for (int z = 0; z < n_padding_byte; z++){
            file.write(reinterpret_cast<char*>(&padding_byte), sizeof(char));
        }
    }

    file.close();
}

int main() {
    int width = 8000;
    int height = 8000;

    createBMP(width, height);
    return 0;
}
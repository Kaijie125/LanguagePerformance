#include <iostream>
#include <fstream>

// alineamiento de memoria
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
    
    // padding = (4 - (width * 3) % 4) % 4;
    uint32_t n_padding_byte = 4 - ((width * 3) % 4);
    if (n_padding_byte == 4){
        n_padding_byte = 0;
    }

    // datos de la cabecera
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

    // escritura de la cabecera
    file.write(reinterpret_cast<char*>(&header), sizeof(BMPHeader));
    
    // uso de un buffer inicializado a 0
    size_t data_size = ((width * 3) + n_padding_byte) * height;
    char* data = (char*)calloc(data_size, sizeof(char));
    int index = 0;

    // colores de la imagen
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            data[index + 2] = static_cast<char>((x / static_cast<float>(width)) * 255);
            data[index + 1] = static_cast<char>(((height - y) / static_cast<float>(height)) * 255);
            data[index] = static_cast<char>((y / static_cast<float>(height)) * 255);
            index += 3;

        }
        index += n_padding_byte;
    }

    file.write(data, data_size);
    free(data);
    file.close();
}

int main() {
    int width = 8000;
    int height = 8000;

    createBMP(width, height);
    return 0;
}
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define N_THREADS 4

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

//alineamiento normal
#pragma pack(pop)

// variables globales
uint32_t n_padding_byte;
char *data;

// argumentos para el hilo
typedef struct {
    int width;
    int height;
    int start_height;
    int end_height;
} threadArgs;

void *generateColor(void *t_args){
    threadArgs args;
    memcpy (&args, t_args, sizeof(threadArgs));

    // colores de la imagen
    int index = args.start_height * (args.width * 3 + n_padding_byte);
    for (int y = args.start_height; y < args.end_height; y++) {
        for (int x = 0; x < args.width; x++) {
            data[index + 2] = (char)((x / (float)args.width) * 255);
            data[index + 1] = (char)(((args.height - y) / (float)args.height) * 255);
            data[index] = (char)((y / (float)args.height) * 255);
            
            index += 3;
        }
        index += n_padding_byte;
    }

    pthread_exit(NULL);
}


void createBMP(int width, int height) {
    
    n_padding_byte = 4 - ((width * 3) % 4);
    if (n_padding_byte == 4){
        n_padding_byte = 0;
    }

    // formato de cabeceras
    BMPHeader header = {
        .type = 0x4D42, 
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

    // buffer para la imagen
    size_t data_size = (width * 3 + n_padding_byte) * height;
    data = (char*)calloc(data_size, sizeof(char));

    // parte hilo
    pthread_t threads[N_THREADS];
    int chunk_size = height / N_THREADS;
    threadArgs t_args[N_THREADS];
    
    for (int i = 0; i < N_THREADS; i++) {
        t_args[i].width = width;
        t_args[i].height = height;
        t_args[i].start_height = i * chunk_size;
        t_args[i].end_height = (i < N_THREADS - 1) ? t_args[i].start_height + chunk_size : height;
        pthread_create(&threads[i], NULL, generateColor, &t_args[i]);
    }

    for (int i = 0; i < N_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    fwrite(data, sizeof(char), data_size, file);
    free(data);
    fclose(file);
}

int main() {
    int width = 8000;
    int height = 8000;

    createBMP(width, height);
    return 0;
}
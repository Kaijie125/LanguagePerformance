#include <stdio.h>

void create_img(const char* img_name, int width, int height) {
    // abre un archivo referenciado por un descriptor
    FILE* img_ds = fopen(img_name, "wb");
    if (!img_ds) {
        printf("Error al abrir el archivo.");
        return;
    }

    // encabezado PNM
    fprintf(img_ds, "P3\n");
    fprintf(img_ds, "%d %d\n", width, height);
    fprintf(img_ds, "255\n");
    
    //int r, g, b;
    // colores del pixel
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = (int)((x / (float)width) * 255);
            int g = (int)(((height - y) / (float)height) * 255);
            int b = (int)((y / (float)height) * 255);
            fprintf(img_ds, "%d %d %d ", r, g, b);
        }
        fprintf(img_ds, "\n");
    }

    fclose(img_ds);
}

int main() {
    int width = 500;
    int height = 500;
    const char* img_name = "image_c.pnm";

    create_img(img_name, width, height);

    return 0;
}
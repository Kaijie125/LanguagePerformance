#include <stdlib.h>
#include <stdio.h>

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    //int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    //int n = sizeof(arr) / sizeof(arr[0]);

    // archivo original
    FILE *file = fopen("../random_list.bin", "rb");
    if (file == NULL) {
        perror("Error al abrir");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    int num = file_size / sizeof(int);
    int *array_int = (int *)malloc(num * sizeof(int));

    fread(array_int, sizeof(int), num, file);

    fclose(file);

    /*
    // txt para comprobar
    FILE *txt_file = fopen("random_list_c.txt", "w");
    if (txt_file == NULL) {
        perror("Error al crear el archivo de texto");
        free(array_int);
        return 1;
    }

    for (int i = 0; i < num; i++) {
        fprintf(txt_file, "%d\n", array_int[i]);
    }

    fclose(txt_file);
    // txt generado
    */

    qsort(array_int, num, sizeof(int), comparar);


    // txt para comprobar
    FILE *txt_file_sorted = fopen("sorted_list_c.txt", "w");
    if (txt_file_sorted == NULL) {
        perror("Error al crear el archivo de texto");
        free(array_int);
        return 1;
    }

    for (int i = 0; i < num; i++) {
        fprintf(txt_file_sorted, "%d\n", array_int[i]);
    }

    fclose(txt_file_sorted);
    // txt generado
    
    free(array_int);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int readRandomBin(int **array_int, int *num){
    FILE *file = fopen("../random_list.bin", "rb");
    if (file == NULL) {
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    *num = file_size / sizeof(int);
    *array_int = (int *)malloc(*num * sizeof(int));

    fread(*array_int, sizeof(int), *num, file);

    fclose(file);
    return 0;
}

int createRandomFile(int *array_int, int num){
    FILE *txt_file = fopen("random_list_c.txt", "w");
    if (txt_file == NULL) {
        return 1;
    }

    for (int i = 0; i < num; i++) {
        fprintf(txt_file, "%d\n", array_int[i]);
    }

    fclose(txt_file);
    return 0;
}

int createSortedFile(int *array_int, int num){
    FILE *txt_file_sorted = fopen("sorted_list_c.txt", "w");
    if (txt_file_sorted == NULL) {
        return 1;
    }

    for (int i = 0; i < num; i++) {
        fprintf(txt_file_sorted, "%d\n", array_int[i]);
    }

    fclose(txt_file_sorted);
    return 0;
}
    
int main() {

    int num;
    int *array_int;
    // archivo original
    if (readRandomBin(&array_int, &num) != 0){
        perror("Error al leer");
        return 1;
    }

    /*
    // txt para comprobar
    if (createRandomFile(array_int, num) != 0){
        perror("Error al crear el archivo de texto");
        free(array_int);
        return 1;
    }
    */

    quickSort(array_int, 0, num - 1);

    // txt para comprobar
    if (createSortedFile(array_int, num) != 0) {
        perror("Error al crear el archivo de texto");
        free(array_int);
        return 1;
    }
    
    free(array_int);

    return 0;
}

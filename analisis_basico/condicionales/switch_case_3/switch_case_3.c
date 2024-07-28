
#include <stdio.h>
#include <stdlib.h>
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

int main() {
    int *array_int;
    int num;

    if (readRandomBin(&array_int, &num) != 0){
        printf("Error reading file");
        return 1;
    }

    for (int i = 0; i < num; i++){
        int value = array_int[i] % 3;
        switch (value) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            default:
                break;
        }

    }
    free(array_int);
    return 0;
}

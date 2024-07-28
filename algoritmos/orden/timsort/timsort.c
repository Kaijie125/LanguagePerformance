#include <stdio.h>
#include <stdlib.h>

#define MIN_MERGE 32

int minRunLength(int n){
    int r = 0;
    while (n >= MIN_MERGE){
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}

// funcion  del insertion sort
void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = temp;
    }
}

// funcion de merge
void merge(int arr[], int l, int m, int r) {
    int len1 = m - l + 1;
    int len2 = r - m;

    int *left = (int *)malloc(len1 * sizeof(int));
    int *right = (int *)malloc(len2 * sizeof(int));

    //copia datos a los arrays temporales
    for (int i = 0; i < len1; i++){
        left[i] = arr[l + i];
    }
        
    for (int j = 0; j < len2; j++){
        right[j] = arr[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    // combina los array
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // copia elementos restantes de left
    while (i < len1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // copia elementos restantes de right
    while (j < len2) {
        arr[k] = right[j];
        j++;
        k++;
    }

    free(left);
    free(right);
}

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

// funcion del timsort
void timSort(int arr[], int n) {
    int minRun = minRunLength(n);

    for (int i = 0; i < n; i += minRun){
        insertionSort(arr, i, min((i + minRun - 1), (n - 1)));
    }

    for (int size = minRun; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n - 1) ? (left + 2 * size - 1) : (n - 1);

            if (mid < right)
                merge(arr, left, mid, right);
        }
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
    int *array_int;
    int num;

    if (readRandomBin(&array_int, &num) != 0){
        printf("Error reading file\n");
        return 1;
    }

    /*
    if (createRandomFile(array_int, num) != 0){
        printf("Error creating file\n");
        return 1;
    }
    */

    timSort(array_int, num);

    if (createSortedFile(array_int, num) != 0){
        printf("Error creating file\n");
        return 1;
    }
    
    free(array_int);
    return 0;
}

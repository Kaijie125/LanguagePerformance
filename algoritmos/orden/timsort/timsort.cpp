#include <iostream>
#include <fstream>

#define MIN_MERGE 32

int minRunLength(int n) {
    int r = 0;
    while (n >= MIN_MERGE) {
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

    int *left = new int[len1];
    int *right = new int[len2];

    //copia datos a los arrays temporales
    for (int i = 0; i < len1; i++) {
        left[i] = arr[l + i];
    }

    for (int j = 0; j < len2; j++) {
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

    delete[] left;
    delete[] right;
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

    for (int i = 0; i < n; i += minRun) {
        insertionSort(arr, i, min((i + minRun - 1), (n - 1)));
    }

    for (int size = minRun; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));

            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

int readRandomBin(int *&array_int, int &num){
    std::ifstream file("../random_list.bin", std::ios::binary);
    if (!file) {
        return 1;
    }

    file.seekg(0, std::ios::end);
    long file_size = file.tellg();
    file.seekg(0, std::ios::beg);

    num = file_size / sizeof(int);
    array_int = new int[num];

    file.read(reinterpret_cast<char*>(array_int), file_size);

    file.close();
    return 0;
}

int createRandomFile(int *array_int, int num){
    std::ofstream txt_file("random_list_cpp.txt");
    if (!txt_file) {
        return 1;
    }

    for (int i = 0; i < num; i++) {
        txt_file << array_int[i] << std::endl;
    }

    txt_file.close();
    return 0;
}

int createSortedFile(int *array_int, int num){
    std::ofstream txt_file_sorted("sorted_list_cpp.txt");
    if (!txt_file_sorted) {
        return 1;
    }

    for (int i = 0; i < num; i++) {
        txt_file_sorted << array_int[i] << std::endl;
    }

    txt_file_sorted.close();
    return 0;
}

int main() {
    
    int num;
    int *array_int;

    // archivo original
    if (readRandomBin(array_int, num) != 0) {
        std::cerr << "Error al abrir" << std::endl;
        return 1;
    }

    /*
    // txt para comprobar
    if (createRandomFile(array_int, num) != 0){
        std::cerr << "Error al crear el archivo de texto" << std::endl;
        delete[] array_int;
        return 1;
    }
    */

    timSort(array_int, num);

    // txt para comprobar
    if (createSortedFile(array_int, num) != 0) {
        std::cerr << "Error al crear el archivo de texto" << std::endl;
        delete[] array_int;
        return 1;
    }

    delete[] array_int;

    return 0;
}

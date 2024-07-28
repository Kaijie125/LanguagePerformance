#include <iostream>
#include <fstream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
        
    quickSort(array_int, 0, num - 1);

    // txt para comprobar
    if (createSortedFile(array_int, num) != 0) {
        std::cerr << "Error al crear el archivo de texto" << std::endl;
        delete[] array_int;
        return 1;
    }

    delete[] array_int;

    return 0;
}

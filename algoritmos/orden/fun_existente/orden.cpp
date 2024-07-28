#include <algorithm>
#include <fstream>
#include <iostream>

int main() {
    //std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    // archivo original
    std::ifstream file("../random_list.bin", std::ios::binary);
    if (!file) {
        std::cerr << "Error al abrir" << std::endl;
        return 1;
    }

    file.seekg(0, std::ios::end);
    long file_size = file.tellg();
    file.seekg(0, std::ios::beg);

    int num = file_size / sizeof(int);
    int *array_int = new int[num];

    file.read(reinterpret_cast<char*>(array_int), file_size);

    file.close();

    /*
    // txt para comprobar
    std::ofstream txt_file("random_list_cpp.txt");
    if (!txt_file) {
        std::cerr << "Error al crear el archivo de texto" << std::endl;
        delete[] array_int;
        return 1;
    }

    for (int i = 0; i < num; i++) {
        txt_file << array_int[i] << std::endl;
    }

    txt_file.close();
    // txt generado
    */

    std::sort(array_int, array_int + num);

    // txt para comprobar
    std::ofstream txt_file_sorted("sorted_list_cpp.txt");
    if (!txt_file_sorted) {
        std::cerr << "Error al crear el archivo de texto" << std::endl;
        delete[] array_int;
        return 1;
    }

    for (int i = 0; i < num; i++) {
        txt_file_sorted << array_int[i] << std::endl;
    }

    txt_file_sorted.close();
    // txt generado

    delete[] array_int;

    return 0;
}

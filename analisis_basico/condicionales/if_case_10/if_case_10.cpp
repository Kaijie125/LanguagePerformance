
#include <iostream>
#include <fstream>
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

int main() {
    
    int num;
    int *array_int;

    if (readRandomBin(array_int, num) != 0) {
        std::cerr << "Error al abrir" << std::endl;
        return 1;
    }

    for (int i = 0; i < num; i++){
        int value = array_int[i] % 10;
        if (value == 0) {
        } else if (value == 1) {
        } else if (value == 2) {
        } else if (value == 3) {
        } else if (value == 4) {
        } else if (value == 5) {
        } else if (value == 6) {
        } else if (value == 7) {
        } else if (value == 8) {
        } else if (value == 9) {
        }
    }
    delete[] array_int;
    return 0;
}

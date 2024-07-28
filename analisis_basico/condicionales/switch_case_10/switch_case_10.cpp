
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
        switch (value) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            default:
                break;
        }

    }
    delete[] array_int;
    return 0;
}

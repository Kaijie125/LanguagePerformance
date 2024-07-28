#include <iostream>
#include <cstring>
// se puede usar tambien 
// const int SIZE = 10000000;
#define SIZE 10000000

int array() {
    /*
    int array_1[SIZE] = {0};
    int array_2[SIZE] = {0};
    int result[SIZE] = {0};
    como en la version de C pero puede producir error
    */
    int *array_1 = new int[SIZE];
    int *array_2 = new int[SIZE];
    int *result = new int[SIZE];
    std::memset(array_1, 0, SIZE * sizeof(int));
    std::memset(array_2, 0, SIZE * sizeof(int));
    std::memset(result, 0, SIZE * sizeof(int));
    
    int acc = 0;

    for (int i = 0; i < SIZE; i++) {
        array_1[i] = i;
    }

    for (int i = 0; i < SIZE; i++) {
        array_2[i] = SIZE - i;
    }

    for (int i = 0; i < SIZE; i++) {
        result[i] = array_1[i] + array_2[i];
    }

    for (int i = 0; i < SIZE; i++) {
        acc = acc + result[i];
    }

    delete[] array_1;
    delete[] array_2;
    delete[] result;
    
    return (int)(acc / SIZE);
}

int main() {
    int size = array();
    std::cout << "Tamanio(" << SIZE << "): " << size << std::endl;
    return 0;
}

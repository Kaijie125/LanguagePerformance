#include <iostream>
#include <vector>

const int SIZE = 10000000;

int array() {
    std::vector<int> array_1(SIZE, 0);
    std::vector<int> array_2(SIZE, 0);
    std::vector<int> result(SIZE, 0);
    int acc = 0;

    for (int i = 0; i < SIZE; ++i) {
        array_1[i] = i;
    }

    for (int i = 0; i < SIZE; ++i) {
        array_2[i] = SIZE - i;
    }

    for (int i = 0; i < SIZE; ++i) {
        result[i] = array_1[i] + array_2[i];
    }

    for (int i = 0; i < SIZE; ++i) {
        acc = acc + result[i];
    }

    return acc / SIZE;
}

int main() {
    int size = array();
    std::cout << "Tamanio(" << SIZE << "): " << size << std::endl;
    return 0;
}
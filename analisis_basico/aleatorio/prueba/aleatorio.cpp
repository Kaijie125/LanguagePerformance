#include <iostream>
#include <cstdlib>
#include <ctime>

#define MIN 0
#define MAX 1000000
#define ITER 100000000

void generateRandom() {
    // similar al generador de C
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Semilla

    int random_num;
    for (int i = 0; i < ITER; i++) {
        random_num = (std::rand() % (MAX - MIN + 1)) + MIN;
    }

}

int main() {
    generateRandom();
    return 0;
}
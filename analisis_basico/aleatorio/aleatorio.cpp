#include <iostream>
#include <random>

#define MIN 0
#define MAX 1000000
#define ITER 100000000

void generateRandom() {
    // inicializa el generador de numeros aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // distribucion de numeros aleatorios entre MIN y MAX (ambos incluidos)
    std::uniform_int_distribution<> distribution(MIN, MAX);

    int random_num;
    for (int i = 0; i < ITER; i++) {
        random_num = distribution(gen);
    }
}

int main() {
    generateRandom();
    return 0;
}
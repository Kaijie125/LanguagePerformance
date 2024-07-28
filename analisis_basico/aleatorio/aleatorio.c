#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define MAX 1000000
#define ITER 100000000

void generateRandom() {
    // semila para generar numero aleatorio
    srand(time(NULL));
    int random_num;

    for(int i = 0; i < ITER; i++) {
        // genera el numero dentro del rango
        // rand() % MAX genera un numero entre 0 y MAX - 1
        random_num = (rand() % (MAX - MIN + 1)) + MIN;
    }

}

int main() {
    generateRandom();
    return 0;
}
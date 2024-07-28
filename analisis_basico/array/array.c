#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// el tamanio no puede ser una variable normal ya que no se resuelve en tiempo de 
// compilacion
#define SIZE 10000000

int array() {
    /* equivalente al memset o bzero sin usar string.h
    int array_1[SIZE] = {0};
    int array_2[SIZE] = {0};
    int result[SIZE] = {0};
    pero puede producir segmentation fault ya que el tamanio es muy grande
    */
    int *array_1 = malloc(sizeof(int) * SIZE);
    int *array_2 = malloc(sizeof(int) * SIZE);
    int *result = malloc(sizeof(int) * SIZE);
    memset(array_1, 0, sizeof(int) * SIZE);
    memset(array_2, 0, sizeof(int) * SIZE);
    memset(result, 0, sizeof(int) * SIZE);

    int acc = 0;

    for (int i = 0; i < SIZE; i++) {
        array_1[i] = i;
    }

    /* 
    for (int i = SIZE; i < 0; i--) {
        array_2[i] = i;
    }
    */ 

    for (int i = 0; i < SIZE; i++) {
        array_2[i] = SIZE - i;
    }

    for (int i = 0; i < SIZE; i++) {
        result[i] = array_1[i] + array_2[i];
    }

    for (int i = 0; i < SIZE; i++) {
        acc = acc + result[i];
    }
    
    free(array_1);
    free(array_2);
    free(result);
    
    return (int) (acc / SIZE);
}

int main() {
    int size = array();
    printf("Tamanio(%d): %d\n", SIZE, size);
}
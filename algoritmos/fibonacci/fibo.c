#include <stdio.h>

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int num = 43;
    
    int result = fibonacci(num);
    printf("Fibonacci(%d): %d\n", num, result);
    
    return 0;
}
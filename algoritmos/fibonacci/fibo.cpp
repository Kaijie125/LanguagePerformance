#include <iostream>

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
    std::cout << "Fibonacci(" << num << "): " << result << std::endl;

    return 0;
}
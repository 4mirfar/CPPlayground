#include <iostream>


int fibonacci(int n) {
    // F(0) = 0, F(1) = 1
    if (n <= 1) {
        return n;
    }
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int m = 10; 

    std::cout << "Fibonacci: ";
    for (int i = 0; i < m; i++) {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
#include <iostream>

long long factorialRecursive(int n) {
    if (n <= 1) return 1; 
    return n * factorialRecursive(n - 1); 
}

int main() {
    int num = 5;
    std::cout << "factorial: " << factorialRecursive(num) << std::endl;
    return 0;
}
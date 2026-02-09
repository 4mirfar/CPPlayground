#include <iostream>

int main() {
    int n = 6;
    long long factArray[n + 1]; 

    factArray[0] = 1; // 0! = 1

    for (int i = 1; i <= n; i++) {
        factArray[i] = i * factArray[i - 1];
    }

    std::cout << "Factorial Array: ";
    for (int i = 0; i <= n; i++) {
        std::cout << i << "!=" << factArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
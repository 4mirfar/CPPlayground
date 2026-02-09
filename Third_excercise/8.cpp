#include <iostream>

int main() {
    int num = 5;
    long long fact = 1;
    int i = num;

    while (i > 1) {
        fact *= i; 
        i--;      
    }

    std::cout << "factorial while loop: " << fact << std::endl;
    return 0;
}
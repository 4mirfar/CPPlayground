#include <iostream>

int main() {
    int n = 10; // Number of terms to print
    int first = 0, second = 1, next;
    int count = 0;

    std::cout << "Fibonacci: ";

    while (count < n) {
        if (count <= 1) {
            next = count;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        
        std::cout << next << " ";
        count++;
    }

    std::cout << std::endl;
    return 0;
}
#include <iostream>

int main() {
    int rows = 3;
    int cols = 6;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if ((i < 2 && j == 0) || (i == 2) || (j == 5) || (i == 1 && j == 1) || (i == 1 && j == 4)) {
                std::cout << "* ";
            } else {
                std::cout << "  "; // Two spaces =  "* " width
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
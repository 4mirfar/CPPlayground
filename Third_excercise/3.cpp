#include <iostream>

int main() {
    int rows = 5;    
    int columns = 6;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if ((i < 2 && j == 0) || (i == 1 && j == 1) || (i == 2) || (i == 3 && j == 4) || (i > 2 && j == columns - 1)) {
                std::cout << "* ";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
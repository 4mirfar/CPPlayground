#include <iostream>
using namespace std;

int main() {
    int n = 3;   // controls the size of the diamond

    // upper part (including middle)
    for (int i = 1; i <= n; i++) {
        for (int space = 1; space <= n - i; space++)
            cout << " ";
        for (int star = 1; star <= 2 * i - 1; star++)
            cout << "*";
        cout << endl;
    }

    // lower part
    for (int i = n - 1; i >= 1; i--) {
        for (int space = 1; space <= n - i; space++)
            cout << " ";
        for (int star = 1; star <= 2 * i - 1; star++)
            cout << "*";
        cout << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int month = 1;

    while (n > 31) {
        n -= 31;
        month++;
    }

    cout << n << "/" << month << endl;

    return 0;
}
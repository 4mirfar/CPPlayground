#include <iostream>
using namespace std;

int main() {
    int mm;
    cin >> mm;

    int m = mm / 1000;
    mm = mm % 1000;

    int cm = mm / 10;
    mm = mm % 10;


    cout << m << "m and " << cm << "cm and " << mm << "mm" << endl;

    return 0;
}
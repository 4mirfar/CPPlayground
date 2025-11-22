#include <iostream>
using namespace std;

int main() {
    int day, month;
    cin >> day >> month;

    int total = (month - 1) * 31 + day;

    cout << total << endl;

    return 0;
}

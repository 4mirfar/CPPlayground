#include <iostream>
using namespace std;

int main() {
    int n, fact=1;
    cout << "enter n: ";
    cin >> n;
    for (int i = 2;i<=n; i++){
        fact = i * fact;
    }

    cout << "fact " << n << " = " << fact ;

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, counter = 0;
    cout << "enter n: ";
    cin >> n;
    for (int i = 1; i <=n; i++){
        if (n % i == 0)
            counter++;
    }
    if (counter == 2)
        cout << n << " is prime" << endl;
    else 
        cout << n << " is not prime" << endl;
    
    return 0;
}
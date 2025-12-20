#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, fact=1, sum=0;
    string text = "";

    cout << "enter n: ";
    cin >> n;
    for (int i = 1; i <n; i++){
        if (n % i == 0){
            sum += i;
        }
    }
    if (sum == n){
        cout << n << " is complete" << endl;
    }
    else {
        cout << n << " is not complete" << endl;
    }

    return 0;
}
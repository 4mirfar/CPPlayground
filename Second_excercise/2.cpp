#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, fact=1, sum=0;
    string text = "";

    cout << "enter n: ";
    cin >> n;
    for (int i = 1; i <=n; i++){
        fact = fact * i;
        sum = sum + fact;
        text = text + to_string(i) + "! + ";
    }
    text.erase(text.size() - 3);
    
    cout << text << " = " <<  sum;

    return 0;
}
// print number from 1 to n recursively

#include <iostream>
using namespace std;

void printTill(int n) {
    if (n < 1) return;
    printTill(n-1);
    cout << n << endl;
}

void printTill2(int x, int n) {
    if (x > n) return;
    cout << x << endl;
    printTill2(x+1, n);
}

void printReverse(int n) {
    if (n < 1) return;
    cout << n << endl;
    printReverse(n-1);
}

int main() {
    int n;
    cin>>n;
    printReverse(n);
    return 0;
}
#include <iostream>
using namespace std;

void printAllDivisorsM1(int n) {
    cout << 1 << '\t';
    for (int i{2}; i<n; i++) {
        if (n%i == 0) cout << i << '\t';
    }
    cout << n << endl;
}

void printAllDivisorsM2(int n) {
    cout << 1 << '\t';
    for (int i{2}; i<=n/2; i++) {
        if (n%i == 0) cout << i << '\t';
    }
    cout << n << endl;
}

void printAllDivisorsM3(int n) {
    cout << 1 << '\t';
    int lim = sqrt(n);
    for (int i{2}; i<=lim; i++)
        if (n%i == 0)
            if (i*i == n) cout << i << '\t';
            else cout << i << '\t' << n/i << '\t';
    cout << n << endl;
}

int main() {
    int n = 16;
    printAllDivisorsM3(n);
    return 0;
}
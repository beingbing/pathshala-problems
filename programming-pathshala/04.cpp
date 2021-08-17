// find if a number is prime or not

#include <iostream>
using namespace std;

bool isPrime(int n) {
    int val = sqrt(n);
    for (int i{2}; i<=val; i++) if (n%i == 0) return false;
    return true;
}

int main() {
    int n;
    cin>>n;
    cout << (isPrime(n) ? "Yes, Prime" : "Not a Prime") << endl;
    return 0;
}
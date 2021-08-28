#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

unsigned long long int m = 1000000007;
vector<long long int> primes(101, 1);
vector<long long int> primesCnt(101, 0);

void primesTill() {
    primes[0] = 0;
    primes[1] = 0;
    int val = sqrt(100);
    for (int i{2}; i <= val; i++)
        if (primes[i] == 1)
            for (int j = i; i * j <= 100; j++)
                primes[i * j] = 0;
}

void countPrimesTill() {
    primesCnt[0] = 0;
    primesCnt[1] = 0;
    for (long long int i{2}; i < 101; i++)
        primesCnt[i] = primesCnt[i - 1] + primes[i];
}

unsigned long long int factorial(unsigned long long int n) {
    if (n == 1 || n == 0)
        return 1;
    return ((n % m) * (factorial(n - 1) % m)) % m;
}

int main() {
    primesTill();
    countPrimesTill();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int primesPresent = primesCnt[n];
        int nonPrimes = n - primesPresent;
        unsigned long long int a = factorial(primesPresent) % m;
        unsigned long long int b = factorial(nonPrimes) % m;
        unsigned long long int ans = (a * b) % m;
        cout << ans << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> getPrimes() {
    vector<bool> isPrime(1000001, true);
    isPrime[1] = false;
    int val = sqrt(1000000);
    for (int i{2}; i <= val; i++)
        if (isPrime[i])
            for (int j{i}; i*j <= 1000000; j++)
                isPrime[i*j] = false;
    vector<int> primes;
    for (int i{1}; i<= 1000000; i++) if (isPrime[i] == 1) primes.push_back(i);
    return primes;
}

int main() {
    vector<int> primes = getPrimes();
    // for (auto i{0}; i<11; i++) cout << primes[i] << endl;
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        vector<bool> isPrime(r-l+1, true);
        for (int i{0}; i < primes.size(); i++) {
            int k = ceil(l*1.0 / primes[i]);
            for (int j{max(k, 2)}; primes[i]*j <= r; j++) {
                isPrime[primes[i]*j - l] = false;
            }
        }
        for (int i{0}; i< isPrime.size(); i++)
            if (isPrime[i] == true) cout << i+l << "\t";
        cout << endl;
    }
    return 0;
}
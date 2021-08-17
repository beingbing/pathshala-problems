// sieve of eratosthenes

#include <iostream>
#include <vector>
using namespace std;

vector<int> primesTill(int n) {
    vector<int> primes(n+1, 1);
    primes[1] = 0;
    int val = sqrt(n);
    for (int i{2}; i<=val; i++)
        if (primes[i] == 1)
            for (int j=i; i*j<=n; j++) primes[i*j] = 0;
    vector<int> ans;
    for (int i{2}; i<=n; i++) if (primes[i] == 1) ans.push_back(i);
    return ans;
}

int main() {
    int n = 100;
    vector<int> ans = primesTill(n);
    for (auto ele : ans) cout << ele << '\t';
    cout << endl;
    return 0;
}

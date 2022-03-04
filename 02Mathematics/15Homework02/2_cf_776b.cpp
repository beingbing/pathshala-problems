#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void primesTill(vector<int>& primes, const int n) {
    int val = sqrt(n);
    for (int i{2}; i<=val; i++)
        if (primes[i] == 1)
            for (int j=i; i*j<=n; j++) primes[i*j] = primes[i] + 1;
}

int main() {
    int n;
    cin>>n;
    vector<int> primes(n+2, 1);
    primesTill(primes, n+1);
    int ans{0};
    for (int i{2}; i<=n+1; i++) if (ans < primes[i]) ans = primes[i];
    cout << ans << endl;
    for (int i{2}; i<=n+1; i++) {
        cout << primes[i];
        if (i != n+1) cout << '\t'; 
    }
    return 0;
}

// not important
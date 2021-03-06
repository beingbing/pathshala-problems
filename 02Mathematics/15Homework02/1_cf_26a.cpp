// almost prime: check if a number has two distinct prime factors or not.

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> primes(3001, 1), spf(3001, -1);

void primesTill() {
    primes[1] = 0;
    for (int i{2}; i*i <= 3001; i++)
        if (primes[i] == 1)
            for (int j = i; i * j <= 3001; j++)
                if (primes[i * j] == 1) {
                    spf[i * j] = i;
                    primes[i * j] = 0;
                }
}

bool primeFactorsM2(int n) {
    set<int> ans;
    while (spf[n] != -1) {
        ans.insert(spf[n]);
        n /= spf[n];
    }
    if (n != 1) ans.insert(n);
    return ans.size() == 2;
}

int main() {
    primesTill();
    int n;
    cin>>n;
    if (n < 6) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> candidates(n+1, 0);
    int ans{0};
    for (int i{6}; i<= n; i++) ans += primeFactorsM2(i);
    cout << ans << endl;
    return 0;
}
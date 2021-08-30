// ~~ implementing sieve of eratosthenes ~~

#include <iostream>
#include <vector>
using namespace std;

// SC = O(n)
// TC = O(n*loglogn)
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

/*
Limitations -
1. space constraints is concerning.
2. if query is for a single number, the O(sqrt(n)) approach discussed in lecture#6 is better.

Advantages -
1. preprocessing time for Q queries will be O(n*loglogn), so total time will be
(n*loglogn + Q) ~~ (n*loglogn)
*/
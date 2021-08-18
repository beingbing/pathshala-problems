// write all the prime factors of a given number

#include <iostream>
#include <vector>
using namespace std;

// tc = O(sqrt(n)*ln) ~~ (sqrt(n)) as ln is way too small
vector<int> primeFactorsM1(int n) {
    vector<int> ans;
    int val = sqrt(n);
    for (int i{2}; i<=val; i++) {
        while (n%i == 0 and n != 1) {
            ans.push_back(i);
            n /= i;
        }
    }
    if (n != 1) ans.push_back(n);
    return ans;
}

// second approach shows you how you can do pre processing,
// if there are too many questions asking about prime factors.
vector<int> primesTill(int n) {
    vector<int> primes(n+1, 1), spf(n+1, -1);
    primes[1] = 0;
    int val = sqrt(n);
    for (int i{2}; i<=val; i++)
        if (primes[i] == 1)
            for (int j=i; i*j<=n; j++)
                if (primes[i*j] == 1) {
                    spf[i*j] = i;
                    primes[i*j] = 0;
                }
    vector<int> ans;
    for (int i{2}; i<=n; i++) if (primes[i] == 1) ans.push_back(i);
    return ans;
}

vector<int> primeFactorsM2(int n) {
    vector<int> ans;
    while (spf[n] != -1) {
        ans.push_back(spf[n]);
        n /= spf[n];
    }
    if (n != 1) ans.push_back(n);
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> ans = primeFactorsM2(n);
    for (auto ele : ans) cout << ele << '\t';
    cout << endl;
    return 0;
}
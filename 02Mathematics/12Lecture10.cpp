// ~~ fast prime factorization ~~
// write all the prime factors of a given number

/*
M1 -
get all the prime number in [1, sqrt(N)] and use only them in M2 of
previous lecture. 
*/


// M2 -
#include <iostream>
#include <vector>
using namespace std;

vector<int> primes, spf;

// second approach shows you how you can do pre processing,
// if there are too many questions asking about prime factors.
/*vector<int>*/
void primesTill(int n) {
    primes.resize(n+1, 1), spf.resize(n+1, -1);
    primes[1] = 0;
    int val = sqrt(n);
    for (int i{2}; i<=val; i++)
        if (primes[i] == 1)
            for (int j=i; i*j<=n; j++)
                if (primes[i*j] == 1) {
                    spf[i*j] = i;
                    primes[i*j] = 0;
                }
    // vector<int> ans;
    // for (int i{2}; i<=n; i++) if (primes[i] == 1) ans.push_back(i);
    // return ans;
}

// TC = O(logn)
vector<int> primeFactorsM2(int n) {
    primesTill(n);
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
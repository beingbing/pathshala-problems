/*

there are two questions which you should ask while writing a DP algorithm.
1. what you can do ?
2. can you do it ?

*/
#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;

vector<long long> prfxSum(100001, 0);

vector<long long> validWaysCnt(100001, -1);

long long calcPossibleWays(long long n, long long& k) {
    if (validWaysCnt[n] != -1) return validWaysCnt[n];
    if (n == 0) return validWaysCnt[n] = 1;
    long long ans{0};
    // we can fill nth place in string by W
    if (n >= k) ans += calcPossibleWays(n-k, k), ans %= mod;
    // we can fill nth place in string by R
    ans += calcPossibleWays(n-1, k), ans %= mod;
    validWaysCnt[n] = ans;
    return validWaysCnt[n];
}

void createPrfxSm(long long& k) {
    prfxSum[0] = validWaysCnt[0];
    for (long long i{1}; i <= 100000; i++) {
        prfxSum[i] = prfxSum[i-1] + calcPossibleWays(i, k);
        prfxSum[i] %= mod;
    }
}

int main() {
    long long t, k;
    cin >> t >> k;
    calcPossibleWays(10000, k);
    createPrfxSm(k);
    while (t--) {
        long long a, b;
        cin >> a >> b;
        long long sum = (prfxSum[b]%mod) - (prfxSum[a-1]%mod);
        if (sum < 0) sum += mod;
        cout << sum << endl;
    }
    return 0;
}

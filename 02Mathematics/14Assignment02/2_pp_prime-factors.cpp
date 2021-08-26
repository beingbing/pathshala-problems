/*

Given a number N, print all its unique prime factors and their exponents in N.

Input Format
The first line of the input contains a single integer T denoting the number of test cases.
The description of T test cases follows.
Each test case contains a single integer N in a separate line.

Output Format
For each test case, for each prime factor of the number N in that test case,
output two space separated integers: the prime factor and its power in N.
Prime factors should be printed in increasing order.

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

vector<int> primes(1000001, 1), spf(1000001, -1);

void primesTill() {
    primes[1] = 0;
    int val = sqrt(1000001);
    for (int i{2}; i <= val; i++)
        if (primes[i] == 1)
            for (int j = i; i * j <= 1000001; j++)
                if (primes[i * j] == 1) {
                    spf[i * j] = i;
                    primes[i * j] = 0;
                }
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
    primesTill();
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> ans = primeFactorsM2(n);
        map<int, int> mp;
        for (auto ele : ans)
            if (mp.find(ele) == mp.end()) mp.insert({ele, 1});
            else mp[ele]++;
        for (auto ele : mp) printf("%d %d\n", ele.first, ele.second);
    }
    return 0;
}
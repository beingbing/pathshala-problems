/*

You are given an array A of N integers.
Count the number of unique prime factors of each element in it.

Input Format
The first line of the input contains a single integer T, denoting the number of test cases.
The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line of each test case contains N space-separated integers A[0],A[1],...,A[N−1].

Output Format
For each test case output a line containing N space separated integers denoting the number of prime factors of each of the array element.

Constraints
1≤T≤10
1≤N≤10^5
1≤Ai≤10^6

Example
Input
1
3
10 12 14
Output
2 2 2

*/
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

vector<int> primes(1000001, 1), spf(1000001, -1);

void primesTill() {
    primes[1] = 0;
    for (int i{2}; i*i <= 1000001; i++)
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
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
		int tmp;
		vector<int> ans;
        for (int i{0}; i<n; i++) {
            cin >> tmp;
            vector<int> vec = primeFactorsM2(tmp);
            map<int, int> mp;
            for (auto ele : vec) mp[ele]++;
            cout << mp.size();
            if (i != n-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
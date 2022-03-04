/*

You are given a non-negative number N, find the number of valid parentheses expressions of that length.
If the answer exists, print the answer modulo 10^9 + 7, otherwise print -1.

Input Format
The first line of the input contains a single integer T denoting the number of test cases.
Each test case contains a single integer N.

Constraints
1 <= T <= 10^3
1 <= N <= 10^3

Output Format
For each test case, output the number number of valid parentheses expressions of length N, on a seperate
line.

Example
Input
2
4
5

Output
2
-1

*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long m = 1000000007;
    vector<int> cnt(501, 0);
    cnt[0] = cnt[1] = 1;
    for (int i{2}; i <= 500; i++)
        for (int j{0}; j < i; j++)
            cnt[i] = (cnt[i] % m + ((cnt[j] % m) * (cnt[i - j - 1] % m)) % m) % m;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 != 0) cout << -1 << endl;
        else cout << cnt[n / 2] % m << endl;
    }
    return 0;
}

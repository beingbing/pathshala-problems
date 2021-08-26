/*
A natural number is called three-prime if it has exactely three divisors.

You are given an array A of N numbers, output the sum of all the three-prime numbers in the array.

Input Format
The first line of the input contains a single integer T denoting the number of test cases.

The description of T test cases follows.

The first line of each test case contains a single integer N.

The second line contains N space-separated integers 
A[0],A[1],...,A[N−1]

Output Format
For each test case, output the sum of all three-prime numbers on a seperate line.

Constraints
1≤T≤10

1≤N≤10^5

1≤Ai≤10^9
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int isTPrime(int n) {
    int val = sqrt(n);
    if (val * val != n) return 0;
    vector<int> ans(1, 1);
    for (int i{2}; i <= val; i++)
        if (n % i == 0)
            if (i * i == n) ans.push_back(i);
            else ans.push_back(i), ans.push_back(n / i);
    ans.push_back(n);
    if (ans.size() == 3) return n;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], ans{0};
        for (int i{0}; i < n; i++) {
            cin >> a[i];
            ans += isTPrime(a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
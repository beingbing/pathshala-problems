/*
You are given a natural number N. Output the sum of all its proper divisors.

A Proper Divisor of a natural number is the divisor that is strictly less than that number.

Input Format
The first line of the input contains a single integer T, denoting the number of test cases.

The description of T test cases follows.

Each test case contains a single integer N.

Output Format
For each test case, output the sum of all proper divisors of N on a seperate line.

Constraints
1≤T≤10^2

1≤N≤10^9
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        int val = sqrt(n);
        int ans{0};
        if (n > 1) ans += 1;
        for (int i{2}; i <= val; i++)
            if (n % i == 0)
                if (i * i == n) ans += i;
                else ans += i + (n / i);
        cout << ans << endl;
    }
    return 0;
}
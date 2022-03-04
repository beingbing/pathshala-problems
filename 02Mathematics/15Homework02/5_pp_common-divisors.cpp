/*
You will be given T pairs of natural numbers A and B.

For each pair, output the number of common divisors between the two numbers.

Input Format
The first line of the input contains a single integer T denoting the number of test cases.

The description of T test cases follows.

The first line of each test case contains two integers A and B.

Output Format
For each test case, output the number of common divisors between the given pair on a seperate line.

Constraints
1≤T≤10^2

1≤A,B≤10^9
*/

#include <iostream>
using namespace std;
typedef long long int ll;

ll findGCDM2(int a, int b) {
    ll x = min(a, b);
    ll y = max(a, b);
    if (x == 0) return y;
    if (y % x == 0) return x;
    return findGCDM2(x, y % x);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b, cnt{1};
        cin >> a >> b;
        ll gcd = findGCDM2(a, b);
        if (gcd != 1) cnt++;
        for (int i{2}; i < gcd; i++) if (a % i == 0 and b % i == 0) cnt++;
        cout << cnt << endl;
    }
    return 0;
}
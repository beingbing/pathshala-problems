/*

Bob have given a integer N he have to find a triplet X, Y and Z
 where each of them are less than or equal to N
 and their LCM is maximum.

Input Format
A single Integer N

Output Format
A single integer, the maximum LCM Bob can achieve.

Constraints
1≤N≤10^6

*/

// if two numbers are to be divisible by 2 (smallest prime),
// how far will they be. Similarly for primes 3, 5 and so on.
// Can we generalise and find what the lcm of top 3 numbers would be?

#include <iostream>
using namespace std;

long long int findGCDM2(long long int a, long long int b) {
    long long int x = min(a, b);
    long long int y = max(a, b);
    if (x == 0) return y;
    if (y%x == 0) return x;
    return findGCDM2(x, y%x);
}

long long int findLCMM2(long long int a, long long int b) {
    long long int gcd = findGCDM2(a, b);
    return (a*b)/gcd;
}

int main() {
    long long int n;
    cin >> n;
    if (n <= 2) {
        cout << n << endl;
        return 0;
    }
    if (n%2 != 0) cout << n*(n-1)*(n-2) << endl;
    else if (findGCDM2(n, n-2) > 1) cout << n*(n-1)*(n-3) << endl;
    else cout << n*(n-1)*(n-2) << endl;
    return 0;
}
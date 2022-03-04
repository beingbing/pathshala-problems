/*

You are given an integer N, output the number of permutations of 1 to N so that prime numbers are at
prime indices (1-indexed.) Since the answer may be large, return the answer modulo 1e9+7.

Input Format
The first line of the input contains a single integer T denoting the number of test cases.
Each test case contains a single integer N.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 100

Output Format
For each test case, output the number of permutations of given type.

Sample Input
1
5

Sample Output
12

Explanation:
For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1] is not because the prime number 5
is at index 1

Example
Input
1
5
Output
12

*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef unsigned long long int ull;

ull m = 1000000007;
vector<ull> primes(101, 1);
vector<ull> primesCnt(101, 0);

void primesTill() {
    primes[0] = 0;
    primes[1] = 0;
    int val = sqrt(100);
    for (int i{2}; i <= val; i++)
        if (primes[i] == 1)
            for (int j = i; i * j <= 100; j++)
                primes[i * j] = 0;
}

void countPrimesTill() {
    primesCnt[0] = 0;
    primesCnt[1] = 0;
    for (ull i{2}; i < 101; i++)
        primesCnt[i] = primesCnt[i - 1] + primes[i];
}

ull factorial(ull n) {
    if (n == 1 || n == 0)
        return 1;
    return ((n % m) * (factorial(n - 1) % m)) % m;
}

int main() {
    primesTill();
    countPrimesTill();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int primesPresent = primesCnt[n];
        int nonPrimes = n - primesPresent;
        ull a = factorial(primesPresent) % m;
        ull b = factorial(nonPrimes) % m;
        ull ans = (a * b) % m;
        cout << ans << endl;
    }
    return 0;
}
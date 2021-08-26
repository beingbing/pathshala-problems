/*

You are given a non-negative number N.
Count the number of prime numbers less than or equal to N.

Input Format
The first line of the input contains a single integer T denoting the number of test cases.
The description of T test cases follows.
Next T lines each contain a single integer N.

Output Format
For each test case, output the number of prime numbers less than or equal to N on a seperate line.

Constraints
1≤T≤10^5

0≤N≤10^6
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long int> primes(1000001, 1);
vector<long long int> primesCnt(1000001, 0);

void primesTill() {
	primes[0] = 0;
    primes[1] = 0;
    int val = sqrt(1000001);
    for (int i{2}; i<=val; i++)
        if (primes[i] == 1)
            for (int j=i; i*j<=1000001; j++) primes[i*j] = 0;
}

void countPrimesTill() {
		primesCnt[0] = 0;
		primesCnt[1] = 0;
		for (long long int i{2}; i<1000001; i++)
				primesCnt[i] = primesCnt[i-1] + primes[i];
}

int main() {
		primesTill();
		countPrimesTill();
		int t;
		cin >> t;
		while (t--) {
				long long int n;
				cin >> n;
				cout << primesCnt[n] << endl;
		}
    return 0;
}
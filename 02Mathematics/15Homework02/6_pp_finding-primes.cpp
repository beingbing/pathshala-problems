/*
General method to calculate all primes in the range 2......N is to start with the number 2,
mark it as prime, and mark all its multiples (excluding itself) as not prime. Then, we find
the next smallest unmarked number, mark it as prime, and mark all its multiples (excluding
itself) as not prime. Continuing this way, we get a list of all primes.

Now, let us say that we modified the above algorithm, and start with N instead of 2. We mark
it as prime, and mark all its factors (excluding itself) as not prime. Then we find the next
greatest unmarked number, mark it as prime, and mark all its factors (excluding itself) as
not prime. Continuing this way, we get a list of all primes.

You are given a natural number N. You run both the original and modified version of finding
primes for numbers from 2..N.

Output the count of integers that are present in both the lists.

Input Format
The first line of the input contains a single integer T denoting the number of test cases.

The description of T test cases follows.

Each test case contains a single integer N in a separate line.

Output Format
For each test case, output the count of numbers marked as a prime on a separate line.

Constraints
1≤T≤10^5

2≤N≤10^6
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
				cout << primesCnt[n]-primesCnt[n/2] << endl;
		}
    return 0;
}
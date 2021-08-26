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
				int a[n];
				vector<int> ans;
				for (int i{0}; i<n; i++) {
						cin >> a[i];
						vector<int> vec = primeFactorsM2(a[i]);
						map<int, int> mp;
						for (auto ele : vec)
								if (mp.find(ele) == mp.end()) mp.insert({ele, 1});
								else mp[ele]++;
						cout << mp.size();
						if (i != n-1) cout << " ";
				}
				cout << endl;
    }
    return 0;
}
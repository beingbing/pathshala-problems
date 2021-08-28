#include <iostream>
#include <vector>
using namespace std;

int main() {
    unsigned long long int t;
    cin >> t;
    while (t--) {
        unsigned long long int n;
        cin >> n;
        if (n%2 != 0) {
            cout << -1 << endl;
            continue;
        }
         n /= 2;
        vector<unsigned long long int> cnt(n+1, 0);
        cnt[0] = cnt[1] = 1;
        unsigned long long int m{1000000007};
        for (unsigned long long int i{2}; i<=n; i++)
            for (unsigned long long int j{0}; j<i; j++)
                cnt[i] += ((cnt[j]%m)*(cnt[i-j-1]%m))%m;
        cout << cnt[n] << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long m = 10e9+7;
    vector<int> cnt(1001, 0);
    cnt[0] = cnt[1] = 1;
    for (int i{2}; i <= 1000; i++) {
        cnt[i] = 0;
        for (int j{0}; j < i; j++)
            cnt[i] = (cnt[i]%m + ((cnt[j]%m)*(cnt[i-j-1]%m))%m)%m;
    }
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

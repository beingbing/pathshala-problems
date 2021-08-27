#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i{0}; i < n; i++) cin >> a[i];
        int k = 4;
        vector<int> cnt(k, 0);
        for (int i{0}; i < n; i++) cnt[a[i] % k]++;
        int ans{0};
        ans += (cnt[0] * (cnt[0] - 1)) / 2;
        for (int i{0}; i < (k / 2); i++) ans += cnt[i] * cnt[k - i];
        if (k % 2 == 0) ans += (cnt[k / 2] * (cnt[k / 2] - 1)) / 2;
        else ans += cnt[k / 2] * cnt[k / 2 + 1];
        cout << ans << endl;
    }
    return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long m, ans = 0;
int main() {
    long long n, x, k;
    cin >> n >> x >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        m = (a[i] - 1) / x + k;
        ans += lower_bound(a.begin(), a.end(), (m + 1) * x) - lower_bound(a.begin(), a.end(), max(m * x, a[i]));
    }
    cout << ans;
}

// maximize equation
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
typedef long long int ll;

int main() {
    int n;
    cin >> n;
    vector<ll> nums(n);
    ll p, q, r;
    cin >> p >> q >> r;
    for (int i{0}; i < n; i++) cin >> nums[i];
    vector<ll> preAr(n), sufAr(n);
    preAr[0] = p * nums[0];
    for (int i{1}; i < n; i++) preAr[i] = max(p * nums[i], preAr[i - 1]);
    sufAr[n - 1] = r * nums[n - 1];
    for (int i{n - 2}; i >= 0; i--) sufAr[i] = max(sufAr[i + 1], r * nums[i]);
    ll ans = LLONG_MIN;
    for (int i{0}; i < n; i++) ans = max(ans, preAr[i] + q * nums[i] + sufAr[i]);
    cout << ans << endl;
    return 0;
}

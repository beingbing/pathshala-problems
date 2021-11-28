#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

int main() {
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    vector<ll> nums(n, 0);
    for (ll i{0}; i<n; i++) cin >> nums[i];
    vector<ll> idxs(n+1, 0);
    ll l, r;
    for (ll i{0}; i<q; i++) {
        cin >> l >> r;
        idxs[r]++;
        idxs[l-1]--;
    }
    for (ll i = n + 1 - 2; i >= 0; i--) idxs[i] += idxs[i + 1];
    sort(idxs.begin(), idxs.end());
    sort(nums.begin(), nums.end());
    ll ans{0};
    for (ll i{0}; i<n; i++) ans += nums[i]*idxs[i+1];
    cout << ans << endl;
    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

struct Operation {
    ll l, r, d;
};

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> nums(n,0);
    for (ll i{0}; i<n; i++) cin >> nums[i];
    vector<Operation> ops(m);
    for (ll i{0}; i<m; i++) cin >> ops[i].l >> ops[i].r >> ops[i].d;
    vector<ll> opsIdx(m+1, 0);
    ll l, r;
    for (ll i{0}; i<k; i++) {
        cin >> l >> r;
        opsIdx[r]++;
        opsIdx[l-1]--;
    }
    for (ll i = m + 1 - 2; i >= 0; i--) opsIdx[i] += opsIdx[i + 1];
    for (ll i{0}; i<m; i++) ops[i].d = ops[i].d * opsIdx[i+1];
    vector<ll> temp(n+1, 0);
    for (ll i{0}; i<m; i++) {
        temp[ops[i].r]+= ops[i].d;
        temp[ops[i].l - 1] -= ops[i].d;
    }
    for (ll i = n + 1 - 2; i >= 0; i--) temp[i] += temp[i + 1];
    for (int i{0}; i<n; i++) {
        nums[i] += temp[i+1];
    }
    for (auto ele : nums) cout << ele << " ";
    cout <<endl;
    return 0;
}
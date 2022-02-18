#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long int ll;

vector<ll> printFirstNegativeInteger(ll arr[], ll n, ll k);

int main() {
    ll t, i;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll arr[n];
        for (i = 0; i < n; i++) cin >> arr[i];
        ll k;
        cin >> k;
        vector<ll> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

vector<ll> printFirstNegativeInteger(ll a[], ll n, ll k) {
    vector<ll> ans;
    queue<ll> q;
    for (int i{0}; i<k; i++) if (a[i] < 0) q.push(i);
    for (int i{k}; i<n; i++) {
        if (q.empty()) ans.push_back(0);
        else ans.push_back(a[q.front()]);
        if (!q.empty() && q.front() == i-k) q.pop();
        if (a[i] < 0) q.push(i);
    }
    if (q.empty()) ans.push_back(0);
    else ans.push_back(a[q.front()]);
    return ans;
}

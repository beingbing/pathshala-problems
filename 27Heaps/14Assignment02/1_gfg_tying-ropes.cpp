#include <iostream>
#include <queue>
using namespace std;
typedef long long int ll;

struct Comp {
    bool operator() (ll& a, ll& b) {
        return a > b;
    }
};

class Solution {
public:
    ll minCost(ll ar[], ll n) {
        priority_queue<ll, vector<ll>, Comp> pq(ar, ar + n);
        ll ans = 0;
        while (pq.size() != 1) {
            ll min1 = pq.top();
            pq.pop();
            ll min2 = pq.top();
            pq.pop();
            ans += min1+min2;
            pq.push(min1+min2);
        }
        return ans;
    }
};

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll i, a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

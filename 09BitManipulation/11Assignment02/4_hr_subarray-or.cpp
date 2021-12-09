#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;


int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i{0}; i<n; i++) cin >> a[i];
    ll ans = 0, mask = 1L << 31;
    for (ll i{31}; i>=0; i--) {
        int next = n; // to know how many possible subarrays on right may have current bit set
        for (ll j{n-1}; j>=0; j--) {
            if (a[j] & mask) next = j;
            ans += (n - next)*mask;
        }
        mask >>= 1;
    }
    cout << ans << endl;
    return 0;
}

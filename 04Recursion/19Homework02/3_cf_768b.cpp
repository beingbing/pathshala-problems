#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long int ll;

ll cnt = 0;
ll l, r;

void helper(ll n, ll lft, ll rgt) {
    if (rgt < lft) return;
    ll mid = lft + (rgt-lft)/2;
    if (lft == mid) {
        if (n == 1 && l <= mid && mid <= r) cnt++;
        return;
    }
    if (lft > r || rgt < l) return;
    helper(n / 2, lft, mid-1);
    helper(n % 2, mid, mid);
    helper(n / 2, mid+1, rgt);
}

int main() {
    ll n;
    cin >> n >> l >> r;
    ll len = 1;
    ll x = log2(n);
    for (int i = 0; i < x; i++) len = len * 2 + 1;
    ll mid = len/2 + 1;
    helper(n/2, 1, mid-1);
    helper(n%2, mid, mid);
    helper(n/2, mid+1, len);
    cout << cnt << endl;
    return 0;
}

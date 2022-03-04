#include <iostream>
using namespace std;
typedef long long int ll;

ll findGCDM2(int a, int b) {
    ll x = min(a, b);
    ll y = max(a, b);
    if (x == 0) return y;
    if (y%x == 0) return x;
    return findGCDM2(x, y%x);
}

ll findLCMM2(ll a, ll b) {
    ll gcd = findGCDM2(a, b);
    return (a*b)/gcd;
}

int main() {
    int t;
    cin >> t;
    ll n,a,b,k;
    while (t--) {
        cin >> n >> a >> b >> k;
        ll lcm = findLCMM2(a, b);
        ll appy = n/a - n/lcm;
        ll chef = n/b - n/lcm;
        if (appy + chef >= k) cout << "Win" << endl;
        else cout << "Lose" << endl;
    }
    return 0;
}
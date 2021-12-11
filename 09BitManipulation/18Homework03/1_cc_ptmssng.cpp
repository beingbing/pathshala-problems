#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll k = 4 * n - 1;
        vector<ll> x(k, 0), y(k, 0);
        for (ll i{0}; i < k; i++) cin >> x[i] >> y[i];
        ll ansX{0}, ansY{0};
        for (auto ele : x) ansX ^= ele;
        for (auto ele : y) ansY ^= ele;
        cout << ansX << " " << ansY << endl;
    }
    return 0;
}

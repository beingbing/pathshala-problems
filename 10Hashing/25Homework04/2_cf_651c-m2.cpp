#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long int ll;

int main() {
    ll n;
    cin >> n;
    ll f, s;
    unordered_map<ll, ll> xFreq, yFreq;
    map<pair<ll, ll>, ll> dups;
    for (ll i{0}; i < n; i++) {
        cin >> f >> s;
        xFreq[f]++;
        yFreq[s]++;
        dups[{f, s}]++;
    }
    ll cnt{0};
    for (auto &ele : xFreq) cnt += ((ele.second * (ele.second - 1)) >> 1);
    for (auto &ele : yFreq) cnt += ((ele.second * (ele.second - 1)) >> 1);
    for (auto &ele : dups) cnt -= ((ele.second * (ele.second - 1)) >> 1);
    cout << cnt << endl;
    return 0;
}

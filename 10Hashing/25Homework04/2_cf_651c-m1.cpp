#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long int ll;

int main() {
    ll n;
    cin >> n;
    ll f, s;
    unordered_map<ll, ll> xFreq, yFreq;
    map<pair<ll, ll>, ll> dups;
    for (ll i{0}; i<n; i++) {
        cin >> f >> s;
        xFreq[f]++;
        yFreq[s]++;
        dups[{f, s}]++;
    }
    ll sameX, sameY, cnt{0};
    for (auto &point : dups) {
        sameX = xFreq[point.first.first]-point.second;
        sameY = yFreq[point.first.second]-point.second;
        cnt += (point.second * (sameX + sameY)) + (point.second * (point.second-1));
    }
    cnt >>= 1;
    cout << cnt << endl;
    return 0;
}

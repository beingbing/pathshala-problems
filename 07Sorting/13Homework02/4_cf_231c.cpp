#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll slow{0}, freq{0}, ele{LLONG_MAX}, preSum{0};
    for (ll fast = 0; fast < n; fast++) {
        preSum += a[fast];
        int curFreq = fast - slow + 1;
        while (curFreq * a[fast] > preSum + k) {
            preSum -= a[slow];
            slow++;
            curFreq = fast - slow + 1;
        }
        if (freq < curFreq) {
            freq = curFreq;
            ele = a[fast];
        } else if (freq == curFreq && ele > a[fast]) ele = a[fast];
    }
    cout << freq << " " << ele << endl;
    return 0;
}

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long int ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i{0}; i<n; i++) cin >> a[i];
    unordered_map<ll, ll> edgeFreq;
    for (auto ele : a) edgeFreq[ele]++;
    ll freq{0};
    for (auto ele : edgeFreq) if (freq < ele.second) freq = ele.second;
    cout << freq << endl;
    return 0;
}

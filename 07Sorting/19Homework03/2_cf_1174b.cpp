#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    bool od{false}, ev{false};
    for (int i{0}; i < n; i++) cin >> a[i];
    for (auto ele : a) {
        if (ev && od) break;
        if (ele%2 == 0) ev = true;
        else if (ele%2 != 0) od = true;
    }
    if (ev && od) sort(a.begin(), a.end());
    for (auto ele : a) cout << ele << " ";
    cout << endl;
    return 0;
}

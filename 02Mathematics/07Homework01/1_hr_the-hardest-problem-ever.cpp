#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

// if GCD of array is != 1 then the subarray with all the elements will make our answer 0
// if GCD of array is 1 then 1^1^1^.... (all 1's) = 1.
// so, if there is a non 1 GCD of given array, answer is 0, otherwise 1.

int findGCDM2(int a, int b) {
    int x = min(a, b);
    int y = max(a, b);
    if (x == 0) return y;
    if (y%x == 0) return x;
    return findGCDM2(x, y%x);
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i{0}; i<n; i++) cin >> a[i];
        ll gcd = a[0];
        for (int i{1}; i<n; i++) gcd = findGCDM2(gcd, a[i]);
        if (gcd == 1) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;

class Solution {
    long long int mod = 1000000007;
public:
    int countWays(int n) {
        long long int ans{0}, f{1}, s{2};
        if (n == 1) return f;
        if (n == 2) return s;
        for (int i{2}; i<n; i++) {
            ans = (f%mod + s%mod) % mod;
            f = s;
            s= ans;
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl;
    }
    return 0;
}

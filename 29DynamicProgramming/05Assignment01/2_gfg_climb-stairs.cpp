#include <iostream>
using namespace std;

class Solution {
    long long int mod = 1000000007;
public:
    int countWays(int n) {
        if (n == 0) return 0;
        long long int f{1}, s{2}, tmp;
        if (n == 1) return f;
        for (int i{3}; i<=n; i++) {
            tmp = (f%mod + s%mod) % mod;
            f = s;
            s= tmp;
        }
        return s;
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

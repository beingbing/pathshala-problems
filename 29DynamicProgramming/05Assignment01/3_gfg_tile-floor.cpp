#include <iostream>
using namespace std;

class Solution {
public:
    long long numberOfWays(long long n) {
        long long ans{0}, f{1}, s{2};
        if (n == 1) return f;
        if (n == 2) return s;
        for (long long i{2}; i<=n; i++) {
            ans = f + s;
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
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}

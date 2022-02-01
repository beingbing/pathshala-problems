#include <iostream>
using namespace std;

class Solution {
public:
    int countWays(int n) {
        int ans{0}, f{1}, s{2};
        for (int i{2}; i<=n; i++) {
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
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl;
    }
    return 0;
}

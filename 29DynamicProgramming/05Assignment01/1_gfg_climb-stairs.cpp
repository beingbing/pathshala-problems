#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<long long int> ans;
    long long int mod = 1000000007;
    
    long long int recurse(int n) {
        if (n == 1) return ans[1];
        if (n == 2) return ans[2];
        if (ans[n] != -1) return ans[n];
        ans[n] =  (countWays(n-1)%mod + countWays(n-2)%mod) % mod;
        return ans[n];
    }

public:
    int countWays(int n) {
        ans.resize(10001, -1);
        ans[1] = 1;
        ans[2] = 2;
        return recurse(n);
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

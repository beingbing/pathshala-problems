#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

class Solution {

    ll maxSum(ll i, vector<long long>& freq, long long& n, vector<long long>& ans) {
        if (i > n) return 0;
        if (ans[i] != -1) return ans[i];
        ans[i] = max(freq[i]*i + maxSum(i+2, freq, n, ans), maxSum(i+1, freq, n, ans));
        return ans[i];
    }

public:
    ll FindMaxSum(vector<long long> freq, ll &n) {
        vector<long long> ans(n+1, -1);
        return maxSum(1, freq, n, ans);
    }
};

int main() {
    ll n;
    cin >> n;
    vector<long long> freq(100001, 0);
    ll tmp, mx{0};
    for (ll i{0}; i<n; i++) {
        cin >> tmp;
        mx = max(mx, tmp);
        freq[tmp]++;
    }
    Solution ob;
    cout << ob.FindMaxSum(freq, mx) << endl;
    return 0;
}

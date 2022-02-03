#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

class Solution {

public:
    int FindMaxSum(int ar[], int n) {
        vector<int> ans(n, -1);
        ans[0] = max(0, ar[0]);
        if (n == 1) return ans[0];
        ans[1] = max(0, max(ar[0], ar[1]));
        for (int i{2}; i<n; i++) ans[i] = max(ar[i] + ans[i-2], ans[i-1]);
        return ans[n-1];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) cin >> a[i];
        Solution ob;
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}

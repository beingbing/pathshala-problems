#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

class Solution {

    int maxSum(int i, int ar[], int& n, vector<int>& ans) {
        if (i>= n) return 0;
        if (ans[i] != -1) return ans[i];
        ans[i] = max(ar[i] + maxSum(i+2, ar, n, ans), maxSum(i+1, ar, n, ans));
        return ans[i];
    }

public:
    int FindMaxSum(int arr[], int n) {
        vector<int> ans(n, -1);
        return maxSum(0, arr, n, ans);
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

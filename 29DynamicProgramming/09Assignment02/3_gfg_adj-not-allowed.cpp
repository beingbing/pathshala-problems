#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {

    int maxSumMat(int i, vector<vector<int>>& mat, int& n, vector<int>& ans) {
        if (i>= n) return 0;
        if (ans[i] != -1) return ans[i];
        ans[i] = max(max(mat[0][i], mat[1][i]) + maxSumMat(i+2, mat, n, ans), maxSumMat(i+1, mat, n, ans));
        return ans[i];
    }

public:
    int maxSum(int n, vector<vector<int>> mat) {
        vector<int> ans(n, -1);
        return maxSumMat(0, mat, n, ans);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(2, vector<int>(N, 0));
        for (int i = 0; i < 2; i++) for (int j = 0; j < N; j++) cin >> mat[i][j];
        Solution ob;
        cout << ob.maxSum(N, mat) << "\n";
    }
    return 0;
}

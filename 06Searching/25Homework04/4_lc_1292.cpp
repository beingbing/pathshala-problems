#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> sumMat;

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 and col1 == 0) return sumMat[row2][col2];
        if (row1 == 0 and col1 > 0) return sumMat[row2][col2] - sumMat[row2][col1 - 1];
        if (row1 > 0 and col1 == 0) return sumMat[row2][col2] - sumMat[row1 - 1][col2];
        return sumMat[row2][col2] - sumMat[row2][col1 - 1] - sumMat[row1 - 1][col2] + sumMat[row1 - 1][col1 - 1];
    }

    int slideSumRegion(int k, int n, int& m) {
        int mn{INT_MAX};
        for (int i{0}; i<n-k; i++) for (int j{0}; j<m-k; j++) mn = min(mn, sumRegion(i, j, i+k, j+k));
        return mn;
    }

public:
    void CalSumMat(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        sumMat = vector<vector<int>>(n, vector<int>(m, 0));
        for (int i{0}; i < n; i++)
            for (int j{0}; j < m; j++)
                if (i > 0 and j > 0)
                    sumMat[i][j] = matrix[i][j] + sumMat[i - 1][j] + sumMat[i][j - 1] - sumMat[i - 1][j - 1];
                else if (i > 0 and j == 0)
                    sumMat[i][j] = matrix[i][j] + sumMat[i - 1][j];
                else if (i == 0 and j > 0)
                    sumMat[i][j] = matrix[i][j] + sumMat[i][j - 1];
                else
                    sumMat[i][j] = matrix[i][j];
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        CalSumMat(mat);
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = min(n, m), mid{0};
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (slideSumRegion(mid, n, m) > threshold) high = mid - 1;
            else {
                if (slideSumRegion(mid+1, n, m) > threshold) return mid+1;
                else low = mid + 1;
            }
        }
        return 0;
    }
};

int main() {
    vector<vector<int>> mat = {{1,1,3,2,4,3,2},{1,1,3,2,4,3,2},{1,1,3,2,4,3,2}};
    int threshold = 4;
    Solution* obj = new Solution();
    cout << obj->maxSideLength(mat, threshold) << endl;
    return 0;
}

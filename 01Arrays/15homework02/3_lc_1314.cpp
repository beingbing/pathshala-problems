#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> sumMat;
    int row, col;

    void createSumMat(vector<vector<int>> &mat) {
        row = mat.size();
        col = mat[0].size();
        sumMat = vector<vector<int>>(row, vector<int>(col, 0));
        for (int i{0}; i < row; i++)
            for (int j{0}; j < col; j++)
                if (i > 0 and j > 0)
                    sumMat[i][j] = mat[i][j] + sumMat[i - 1][j] + sumMat[i][j - 1] - sumMat[i - 1][j - 1];
                else if (i > 0 and j == 0)
                    sumMat[i][j] = mat[i][j] + sumMat[i - 1][j];
                else if (i == 0 and j > 0)
                    sumMat[i][j] = mat[i][j] + sumMat[i][j - 1];
                else
                    sumMat[i][j] = mat[i][j];
    }

    int findMin(int val, int ofst) {
        return val-ofst >= 0 ? val-ofst : 0; 
    }

    int findMax(int val, int lim, int ofst) {
        return val+ofst < lim ? val+ofst : lim-1; 
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 and col1 == 0) return sumMat[row2][col2];
        if (row1 == 0 and col1 > 0) return sumMat[row2][col2] - sumMat[row2][col1 - 1];
        if (row1 > 0 and col1 == 0) return sumMat[row2][col2] - sumMat[row1 - 1][col2];
        return sumMat[row2][col2] - sumMat[row2][col1 - 1] - sumMat[row1 - 1][col2] + sumMat[row1 - 1][col1 - 1];
    }

public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k) {
        createSumMat(mat);
        vector<vector<int>> res(row, vector<int>(col, 0));
        int row1, col1, row2, col2;
        for (int i{0}; i<row; i++) {
            for (int j{0}; j<col; j++) {
                row1 = findMin(i, k);
                col1 = findMin(j, k);
                row2 = findMax(i, row, k);
                col2 = findMax(j, col, k);
                res[i][j] = sumRegion(row1, col1, row2, col2);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> mat = {{67,64,78},{99,98,38},{82,46,46},{6,52,55},{55,99,45}};
    Solution *obj = new Solution();
    vector<vector<int>> ans = obj->matrixBlockSum(mat, 3);
    for (auto row : ans) for (auto ele : row) cout << ele << endl;
    return 0;
}
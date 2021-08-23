// range queries

#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
    vector<vector<int> > sumMat;

public:
    NumMatrix(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        sumMat = vector<vector<int> >(n, vector<int>(m, 0));
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

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 and col1 == 0) return sumMat[row2][col2];
        if (row1 == 0 and col1 > 0) return sumMat[row2][col2] - sumMat[row2][col1 - 1];
        if (row1 > 0 and col1 == 0) return sumMat[row2][col2] - sumMat[row1 - 1][col2];
        return sumMat[row2][col2] - sumMat[row2][col1 - 1] - sumMat[row1 - 1][col2] + sumMat[row1 - 1][col1 - 1];
    }
};

int main() {
    vector<vector<int> > matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}};
    NumMatrix *obj = new NumMatrix(matrix);
    int ans = obj->sumRegion(2, 1, 4, 3);
    cout << ans << endl;
    return 0;
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
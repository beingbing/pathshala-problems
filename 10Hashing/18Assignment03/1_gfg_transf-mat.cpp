#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void booleanMatrix(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row(m, 0), col(n, 0);
        for (int i{0}; i < m; i++)
            for (int j{0}; j < n; j++)
                if (mat[i][j] == 1)
                    row[i] = 1, col[j] = 1;
        for (int i{0}; i < m; i++)
            for (int j{0}; j < n; j++)
                if (row[i] == 1 || col[j] == 1)
                    mat[i][j] = 1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int row, col;
        cin >> row >> col;
        vector<vector<int>> matrix(row);
        for (int i = 0; i < row; i++) {
            matrix[i].assign(col, 0);
            for (int j = 0; j < col; j++)
                cin >> matrix[i][j];
        }
        Solution ob;
        ob.booleanMatrix(matrix);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}

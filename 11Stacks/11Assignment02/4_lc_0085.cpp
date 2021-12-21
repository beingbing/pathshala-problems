#include <climits>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {

    int largestRectangleArea(vector<int>& ht) {
        int n = ht.size();
        if (n == 0) return 0;
        vector<int> nse(n), pse(n);
        stack<int> s;
        s.push(0);
        for (int i{0}; i<n; i++) {
            while (!s.empty() && ht[i] < ht[s.top()]) {
                nse[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            nse[s.top()] = n;
            s.pop();
        }
        s.push(n-1);
        for (int i{n-2}; i>=0; i--) {
            while (!s.empty() && ht[i] < ht[s.top()]) {
                pse[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            pse[s.top()] = -1;
            s.pop();
        }
        int maxArea = INT_MIN;
        for (int i{0}; i<n; i++) {
            maxArea = max(maxArea, ht[i]*(nse[i]-pse[i]-1));
        }
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> mat(rows, vector<int>(cols, 0));
        for (int i{0}; i<rows; i++) for (int j{0}; j<cols; j++) if (matrix[i][j] == '1') mat[i][j] = 1;
        for (int c{0}; c<cols; c++)
            for (int r{1}; r<rows; r++)
                if (mat[r][c] != 0) mat[r][c] = 1 + mat[r-1][c];
        int maxArea = INT_MIN;
        for (int r{0}; r<rows; r++) maxArea = max(maxArea, largestRectangleArea(mat[r]));
        return maxArea;
    }
};

int main() {
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    Solution obj;
    cout << obj.maximalRectangle(matrix) << endl;
    return 0;
}

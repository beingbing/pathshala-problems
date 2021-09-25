#include <iostream>
#include <vector>
using namespace std;

class Solution {

    vector<string> ans;

    bool isSafe(vector<vector<int>> &grid, int i, int j) {
        int n = grid.size();
        if (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 1) return true;
        return false;
    }

    void findPaths(vector<vector<int>> &grid, string route, int i, int j) {
        if (i == j and j == grid.size() - 1) {
            ans.push_back(route);
            return;
        }
        grid[i][j] = 0;
        if (isSafe(grid, i + 1, j)) findPaths(grid, route + "D", i + 1, j);
        if (isSafe(grid, i, j - 1)) findPaths(grid, route + "L", i, j - 1);
        if (isSafe(grid, i, j + 1)) findPaths(grid, route + "R", i, j + 1);
        if (isSafe(grid, i - 1, j)) findPaths(grid, route + "U", i - 1, j);
        grid[i][j] = 1;
    }

public:
    vector<string> uniquePathsIII(int &n, vector<vector<int>> &grid) {
        findPaths(grid, "", 0, 0);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, 0));
        for (int i{0}; i < n; i++) for (int j{0}; j < n; j++) cin >> grid[i][j];
        Solution *obj = new Solution();
        vector<string> ans = obj->uniquePathsIII(n, grid);
        for (auto ele : ans) cout << ele << " ";
        cout << endl;
    }
    return 0;
}

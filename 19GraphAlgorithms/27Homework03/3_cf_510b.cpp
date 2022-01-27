#include <iostream>
#include <vector>
using namespace std;

class Solution {

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    void dfs(int i, int j, int prvi, int prvj, vector<vector<bool>> &visited, bool &hasCycle, vector<vector<char>> &grid) {
        if (visited[i][j]) {
            hasCycle = true;
            return;
        }
        visited[i][j] = true;
        for (auto &dir : directions) {
            int newi = i + dir.first;
            int newj = j + dir.second;
            if (newi >= 0 && newi < grid.size() && newj >= 0 && newj < grid[0].size() && grid[newi][newj] == grid[i][j] && !(newi == prvi && newj == prvj))
                dfs(newi, newj, i, j, visited, hasCycle, grid);
        }
    }

public:
    bool containsCycle(vector<vector<char>> &grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        bool hasCycle = false;
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (!visited[i][j])
                    dfs(i, j, -1, -1, visited, hasCycle, grid);
        return hasCycle;
    }
};

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<char>> grid(row, vector<char>(col, '.'));
    for (int i{0}; i<row; i++) {
        for (int j{0}; j<col; j++) {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    bool ans = obj.containsCycle(grid);
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

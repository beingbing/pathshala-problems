#include <vector>
using namespace std;

class Solution {
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> visited;

    bool isValid(int& r, int& c, int& row, int& col, vector<vector<char>>& mat) {
        return r >= 0 && r < row && c >= 0 && c < col && mat[r][c] == '1';
    }

    void dfs(int r, int c, int& row, int& col, vector<vector<char>>& grid) {
        if (!isValid(r, c, row, col, grid) || visited[r][c]) return;
        visited[r][c] = true;
        for (int i{0}; i<directions.size(); i++)
            dfs(r+directions[i].first, c+directions[i].second, row, col, grid);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (!row) return row;
        int col = grid[0].size();
        visited.resize(row, vector<int>(col, 0));
        int ans{0};
        for (int i{0}; i<row; i++)
            for (int j{0}; j<col; j++)
                if (!visited[i][j] && grid[i][j] == '1') ans++, dfs(i, j, row, col, grid);
        return ans;
    }
};

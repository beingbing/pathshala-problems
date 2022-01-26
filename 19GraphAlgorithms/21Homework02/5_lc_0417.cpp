#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<pair<int, int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(int i, int j, int& row, int& col, vector<vector<bool>>& reachable, vector<vector<int>>& hts) {
        if (reachable[i][j]) return;
        reachable[i][j] = true;
        for (auto &dir : directions) {
            if (i + dir.first < 0 || i + dir.first >= row || j + dir.second < 0 || j + dir.second >= col) continue;
            if (hts[i + dir.first][j + dir.second] < hts[i][j]) continue;
            dfs(i + dir.first, j + dir.second, row, col, reachable, hts);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& hts) {
        int row = hts.size(), col = hts[0].size();
        vector<vector<bool>> intoPac(row, vector<bool>(col, false));
        vector<vector<bool>> intoAtl(row, vector<bool>(col, false));
        for (int i{0}; i < row; i++) {
            dfs(i, 0, row, col, intoPac, hts);
            dfs(i, col - 1, row, col, intoAtl, hts);
        }
        for (int i{0}; i < col; i++) {
            dfs(0, i, row, col, intoPac, hts);
            dfs(row - 1, i, row, col, intoAtl, hts);
        }
        vector<vector<int>> commonCells;
        for (int i{0}; i<row; i++)
            for (int j{0}; j<col; j++)
                if (intoPac[i][j] && intoAtl[i][j]) commonCells.push_back({i,j});
        return commonCells;
    }
};

int main() {
    vector<vector<int>> hts = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    Solution obj;
    vector<vector<int>> cells = obj.pacificAtlantic(hts);
    for (auto &ele : cells) {
        for (auto &num : ele) cout << num << " ";
        cout << endl;
    }
    return 0;
}

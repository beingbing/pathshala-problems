#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
    bool isvalid{false};

    void dfs(int si, int sj, int& row, int& col, vector<vector<char>> &maze, int& ei, int& ej) {
        if (si < 0 || si >= row || sj < 0 || sj >= col) return;
        if (maze[si][sj] == '#' || maze[si][sj] == 'A') return;
        maze[si][sj] = 'A';
        if (si == ei && sj == ej) isvalid = true;
        dfs(si+1, sj, row, col, maze, ei, ej);
        dfs(si-1, sj, row, col, maze, ei, ej);
        dfs(si, sj+1, row, col, maze, ei, ej);
        dfs(si, sj-1, row, col, maze, ei, ej);
    }

public:
    bool isMazeValid(int& row, int& col, vector<vector<char>>& maze) {
        set<pair<int, int>> edges;
        for (int i{0}; i<col; i++) if (maze[0][i] == '.') edges.insert({0,i});
        for (int i{0}; i<col; i++) if (maze[row-1][i] == '.') edges.insert({row-1,i});
        for (int i{0}; i<row; i++) if (maze[i][0] == '.') edges.insert({i,0});
        for (int i{0}; i<row; i++) if (maze[i][col-1] == '.') edges.insert({i,col-1});
        if (edges.size() != 2) return false;
        vector<pair<int, int>> points;
        for (auto &ele : edges) points.push_back(ele);
        pair<int, int> strt = points[0], nd = points[1];
        dfs(strt.first, strt.second, row, col, maze, nd.first, nd.second);
        return isvalid;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int row, col;
        cin >> row >> col;
        vector<vector<char>> maze(row, vector<char>(col));
        for (int i{0}; i<row; i++) for (int j{0}; j<col; j++) cin >> maze[i][j];
        Solution obj;
        bool ans = obj.isMazeValid(row, col, maze);
        if (ans) cout << "valid" << endl;
        else cout << "invalid" << endl;
    }
    return 0;
}

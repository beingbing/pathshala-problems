#include <iostream>
#include <vector>
using namespace std;

class Solution {

    vector<string> ans;

    bool isSafe(vector<vector<int>>& grid, int i, int j) {
        if (i >= grid.size()) return false;
        if (j >= grid[0].size()) return false;
        if (grid[i][j] == -1) return false;
        return true;
    }

    void findPaths(vector<vector<int>>& grid, vector<vector<int>>& isVisited, string route, int i, int j) {
        if (isVisited[i][j] == 1) return;
        if (i == j and j == grid.size()-1) {
            ans.push_back(route);
            return;
        }
        isVisited[i][j] = 1;
        if (isSafe(grid, i, j+1) and !isVisited[i][j+1]) {
            findPaths(grid, isVisited, route + "R", i, j+1);
            route.pop_back();
        }
        if (isSafe(grid, i, j-1) and !isVisited[i][j-1]) {
            findPaths(grid, isVisited, route + "L", i, j-1);
            route.pop_back();
        }
        if (isSafe(grid, i+1, j) and !isVisited[i+1][j]) {
            findPaths(grid, isVisited, route + "D", i+1, j);
            route.pop_back();
        }
        if (isSafe(grid, i-1, j) and !isVisited[i-1][j]) {
            findPaths(grid, isVisited, route + "U", i-1, j);
            route.pop_back();
        }
        isVisited[i][j] = 0;
    }

public:
    vector<string> uniquePathsIII(int& n, vector<vector<int>>& grid, vector<vector<int>>& isVisited) {
        findPaths(grid, isVisited, "", 0, 0);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n,0)), isVisited(n, vector<int>(n,0));
        for (int i{0}; i<n; i++) for (int j{0}; j<n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 0) isVisited[i][j] = 1;
        }
        Solution* obj = new Solution();
        vector<string> ans = obj->uniquePathsIII(n, grid, isVisited);
        for (auto ele : ans) cout << ele << " ";
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> isVisited;

    bool isSafe(vector<vector<int>>& grid, int i, int j) {
        if (i >= grid.size()) return false;
        if (j >= grid[0].size()) return false;
        if (grid[i][j] == -1) return false;
        return true;
    }

    int countPaths(vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] == 2) return 1;
        isVisited[i][j] = 1;
        int sum{0};
        if (isSafe(grid, i, j+1) and !isVisited[i][j+1]) sum += countPaths(grid, i, j+1);
        if (isSafe(grid, i, j-1) and !isVisited[i][j-1]) sum += countPaths(grid, i, j-1);
        if (isSafe(grid, i+1, j) and !isVisited[i+1][j]) sum += countPaths(grid, i+1, j);
        if (isSafe(grid, i-1, j) and !isVisited[i-1][j]) sum += countPaths(grid, i-1, j);
        isVisited[i][j] = 0;
        return sum;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int strti, strtj;
        int n = grid.size();
        int m = grid[0].size();
        isVisited.resize(n, vector<int>(m, 0));
        for (auto i{0}; i<n; i++)
            for (auto j{0}; j<m; j++)
                if (grid[i][j] == 1) strti = i, strtj = j;
        return countPaths(grid, strti, strtj);
    }
};

int main() {
    vector<vector<int>> grid = {{1,0,0,0},{0,0,2,-1}};
    Solution* obj = new Solution();
    cout << obj->uniquePathsIII(grid) << endl;
    return 0;
}
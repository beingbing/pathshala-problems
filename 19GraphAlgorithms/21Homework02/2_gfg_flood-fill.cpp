#include <iostream>
#include <vector>
using namespace std;

class Solution {

    void dfs(int i, int j, int& row, int& col, vector<vector<int>> &image, int& oldClr, int& newColor) {
        if (i < 0 || i >= row || j < 0 || j >= col) return;
        if (image[i][j] != oldClr) return;
        image[i][j] = newColor;
        dfs(i+1, j, row, col, image, oldClr, newColor);
        dfs(i-1, j, row, col, image, oldClr, newColor);
        dfs(i, j+1, row, col, image, oldClr, newColor);
        dfs(i, j-1, row, col, image, oldClr, newColor);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        int row = image.size();
        if (!row) return image;
        int col = image[0].size();
        int oldClr = image[sr][sc];
        if (oldClr == newColor) return image;
        dfs(sr, sc, row, col, image, oldClr, newColor);
        return image;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> image[i][j];
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i) cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}

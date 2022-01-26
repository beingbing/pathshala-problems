#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int cnt{0};

    void dfs(int i, int j, int l, int& dep, int& row, int& col, vector<vector<vector<char>>>& plate) {
        if (i < 0 || i >= dep || j < 0 || j >= row || l < 0 || l >= col) return;
        if (plate[i][j][l] == '#' || plate[i][j][l] == 'x') return;
        plate[i][j][l] = 'x';
        cnt++;
        dfs(i+1, j, l, dep, row, col, plate);
        dfs(i-1, j, l, dep, row, col, plate);
        dfs(i, j+1, l, dep, row, col, plate);
        dfs(i, j-1, l, dep, row, col, plate);
        dfs(i, j, l+1, dep, row, col, plate);
        dfs(i, j, l-1, dep, row, col, plate);
    }

public:
    int floodFill(vector<vector<vector<char>>>& plate, int& sr, int& sc, int& z, int& x, int& y) {
        dfs(0, sr, sc, z, x, y, plate);
        return cnt;
    }
};

int main() {
    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<vector<char>>> plate(k, vector<vector<char>>(n, vector<char>(m, '.')));
    for (int i{0}; i<k; i++) for (int j{0}; j<n; j++) for (int l{0}; l<m; l++) cin >> plate[i][j][l];
    int x, y;
    cin >> x >> y;
    x--, y--;
    Solution obj;
    int ans = obj.floodFill(plate, x, y, k, n, m);
    cout << ans << endl;
    return 0;
}

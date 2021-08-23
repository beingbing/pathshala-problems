#include <iostream>
#include <vector>
using namespace std;

int getBrghtness(int row1, int col1, int row2, int col2, vector<vector<vector<int>>>& brightness, int k) {
        if (row1 == 0 and col1 == 0) return brightness[row2][col2][k];
        if (row1 == 0 and col1 > 0) return brightness[row2][col2][k] - brightness[row2][col1 - 1][k];
        if (row1 > 0 and col1 == 0) return brightness[row2][col2][k] - brightness[row1 - 1][col2][k];
        return brightness[row2][col2][k] - brightness[row2][col1 - 1][k] - brightness[row1 - 1][col2][k] + brightness[row1 - 1][col1 - 1][k];
}

int main() {
    int n, q, c;
    cin >> n >> q >> c;
    vector<vector<vector<int>>> stars(101, vector<vector<int>>(101, vector<int>(c + 1, 0)));
    int x, y, s;
    for (int i{0}; i < n; i++) {
        cin >> x >> y >> s;
        stars[x][y][0] += s++;
        for (int k{1}; k <= c; k++) stars[x][y][k] += ((s++) % (c + 1));
    }
    vector<vector<vector<int>>> brightness(101, vector<vector<int>>(101, vector<int>(c + 1, 0)));
    for (int k{0}; k <= c; k++)
        for (int i{0}; i < 101; i++)
            for (int j{0}; j < 101; j++)
                if (i > 0 and j > 0)
                    brightness[i][j][k] = stars[i][j][k] + brightness[i - 1][j][k] + brightness[i][j - 1][k] - brightness[i - 1][j - 1][k];
                else if (i > 0 and j == 0)
                    brightness[i][j][k] = stars[i][j][k] + brightness[i - 1][j][k];
                else if (i == 0 and j > 0)
                    brightness[i][j][k] = stars[i][j][k] + brightness[i][j - 1][k];
                else
                    brightness[i][j][k] = stars[i][j][k];
    int t, x1, y1, x2, y2, ans;
    while (q--) {
        ans = 0;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        t = t%(c+1);
        ans += getBrghtness(x1, y1, x2, y2, brightness, t);
        cout << ans << endl;
    }
    return 0;
}
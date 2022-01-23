#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    queue<pair<int, int>> q;
    int r, c, len = INT_MAX, ans = 0;
    cin >> r >> c;
    vector<vector<int>> dist(r, vector<int>(c));
    vector<vector<char>> forest(r, vector<char>(c));
    vector<vector<bool>> visited(r, vector<bool>(c));
    vector<pair<int, int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> forest[i][j];
            if (forest[i][j] == 'E') {
                q.push(make_pair(i, j));
                visited[i][j] = 1;
            }
        }
    }
    while (!q.empty()) {
        pair<int, int> x = q.front();
        q.pop();
        for (int k = 0; k < directions.size(); k++) {
            int i = x.first + directions[k].first;
            int j = x.second + directions[k].second;
            if (i >= 0 && j >= 0 && i < r && j < c && forest[i][j] != 'T' && !visited[i][j]) {
                visited[i][j] = true;
                q.push(make_pair(i, j));
                dist[i][j] = dist[x.first][x.second] + 1;
                if (forest[i][j] == 'S') len = dist[i][j];
                else if (dist[i][j] <= len) ans += forest[i][j] - '0';
            }
        }
    }
    cout << ans << endl;
    return 0;
}

#include <queue>
#include <vector>
using namespace std;

class GraphNode {
public:
    int row, col, dist;

    GraphNode(int r, int c): row{r}, col{c}, dist{0} {} 

    GraphNode(int r, int c, int d): row{r}, col{c}, dist{d} {} 
};

class Solution {

    bool isValid(int row, int col, int &r, int &c) {
        return row >= 0 && row < r && col >= 0 && col < c;
    }

public:
    int orangesRotting(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();
        vector<vector<int>> visited(r, vector<int>(c,0));
        int ans{0};
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<GraphNode*> q;
        for (int i{0}; i<r; i++)
            for (int j{0}; j<c; j++)
                if (mat[i][j] == 2) visited[i][j] = 1, q.push(new GraphNode(i, j));
        while (!q.empty()) {
            GraphNode* x = q.front();
            q.pop();
            if (visited[x->row][x->col]) ans = max(ans, x->dist), mat[x->row][x->col] = 0;
            for (int i{0}; i<directions.size(); i++) {
                if (!isValid(x->row + directions[i].first, x->col + directions[i].second, r, c) || visited[x->row + directions[i].first][x->col + directions[i].second] || mat[x->row + directions[i].first][x->col + directions[i].second] != 1) continue;
                GraphNode* adj = new GraphNode(x->row + directions[i].first, x->col + directions[i].second, x->dist + 1);
                visited[adj->row][adj->col] = 1;
                q.push(adj);
            }
        }
        bool freshLeft{false};
        for (auto &rw : mat) for (auto &ele : rw) if (ele == 1) {freshLeft = true; break;}
        return freshLeft ? -1 : ans;
    }
};

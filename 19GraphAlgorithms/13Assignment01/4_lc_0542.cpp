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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();
        vector<vector<int>> visited(r, vector<int>(c,0)), ans(r, vector<int>(c, 0));
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<GraphNode*> q;
        for (int i{0}; i<r; i++)
            for (int j{0}; j<c; j++)
                if (mat[i][j] == 0) visited[i][j] = 1, q.push(new GraphNode(i, j));
        while (!q.empty()) {
            GraphNode* x = q.front();
            q.pop();
            if (visited[x->row][x->col]) ans[x->row][x->col] = x->dist;
            for (int i{0}; i<directions.size(); i++) {
                if (!isValid(x->row + directions[i].first, x->col + directions[i].second, r, c) || visited[x->row + directions[i].first][x->col + directions[i].second]) continue;
                GraphNode* adj = new GraphNode(x->row + directions[i].first, x->col + directions[i].second, x->dist + 1);
                visited[adj->row][adj->col] = 1;
                q.push(adj);
            }
        }
        return ans;
    }
};

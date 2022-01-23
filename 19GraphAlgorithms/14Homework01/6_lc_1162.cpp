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

    bool isValid(int row, int col, int &n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }

public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n,0));
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<GraphNode*> q;
        for (int i{0}; i<n; i++)
            for (int j{0}; j<n; j++)
                if (grid[i][j] == 1) visited[i][j] = 1, q.push(new GraphNode(i, j));
        int mx{-1};
        while (!q.empty()) {
            GraphNode* x = q.front();
            q.pop();
            if (visited[x->row][x->col]) mx = max(mx, x->dist);
            for (int i{0}; i<directions.size(); i++) {
                if (!isValid(x->row + directions[i].first, x->col + directions[i].second, n) || visited[x->row + directions[i].first][x->col + directions[i].second]) continue;
                GraphNode* adj = new GraphNode(x->row + directions[i].first, x->col + directions[i].second, x->dist + 1);
                visited[adj->row][adj->col] = 1;
                q.push(adj);
            }
        }
        return mx ? mx : -1;
    }
};

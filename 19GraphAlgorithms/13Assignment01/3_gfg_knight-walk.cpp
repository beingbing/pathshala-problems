#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class GraphNode {
public:
    int row, col, dist;

    GraphNode(int r, int c): row{r}, col{c}, dist{0} {} 

    GraphNode(int r, int c, int d): row{r}, col{c}, dist{d} {} 
};

// class Graph {
//     GraphNode *root;

// public:
//     Graph(): root{new GraphNode()} {}

//     Graph(int r, int c): root{new GraphNode(r, c)} {}

//     void insert() {
//         //
//     }
// };

class Solution {

    bool isValid(int row, int col, int &n) {
        return row > 0 && row <= n && col > 0 && col <= n;
    }

public:
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n) {
        queue<GraphNode*> q;
        vector<vector<int>> visited(n+1, vector<int>(n+1,0));
        vector<pair<int, int>> directions = {
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
        };
        int ans{-1};
        visited[KnightPos[0]][KnightPos[1]] = 1;
        q.push(new GraphNode(KnightPos[0], KnightPos[1]));
        GraphNode* dest = new GraphNode(TargetPos[0], TargetPos[1]);
        while (!q.empty()) {
            GraphNode* x = q.front();
            q.pop();
            if (x->row == dest->row && x->col == dest->col) {ans = x->dist; break;}
            for (int i{0}; i<directions.size(); i++) {
                if (!isValid(x->row + directions[i].first, x->col + directions[i].second, n) || visited[x->row + directions[i].first][x->col + directions[i].second]) continue;
                GraphNode* adj = new GraphNode(x->row + directions[i].first, x->col + directions[i].second, x->dist + 1);
                visited[adj->row][adj->col] = 1;
                q.push(adj);
            }
        }
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
}

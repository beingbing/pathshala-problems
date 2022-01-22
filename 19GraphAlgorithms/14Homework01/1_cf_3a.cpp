#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class GraphNode {
public:
    int row, col, dist;
    vector<string> moves;

    GraphNode(int& r, int& c): row{r}, col{c}, dist{0} {} 

    GraphNode(int r, int c, int d): row{r}, col{c}, dist{d} {} 
};

class Moves {
public:
    int x, y;
    string name;
    Moves(int x, int y, string mv): x{x}, y{y}, name{mv} {}
};

class Solution {

    bool isValid(int row, int col, int &n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }

public:
    GraphNode* minStepToReachTarget(pair<int, int> KingPos, pair<int, int> TargetPos, int n) {
        queue<GraphNode*> q;
        vector<vector<int>> visited(n, vector<int>(n,0));
        vector<Moves*> directions = {
            new Moves(1, 0, "R"), new Moves(-1, 0, "L"), new Moves(0, 1, "U"), new Moves(0, -1, "D"),
            new Moves(1, 1, "RU"), new Moves(-1, 1, "LU"), new Moves(1, -1, "RD"), new Moves(-1, -1, "LD")
        };
        vector<GraphNode*> ans;
        visited[KingPos.first][KingPos.second] = 1;
        q.push(new GraphNode(KingPos.first, KingPos.second));
        GraphNode* dest = new GraphNode(TargetPos.first, TargetPos.second);
        while (!q.empty()) {
            GraphNode* x = q.front();
            q.pop();
            if (x->row == dest->row && x->col == dest->col) return x;
            for (int i{0}; i<directions.size(); i++) {
                if (!isValid(x->row + directions[i]->x, x->col + directions[i]->y, n) || visited[x->row + directions[i]->x][x->col + directions[i]->y]) continue;
                GraphNode* adj = new GraphNode(x->row + directions[i]->x, x->col + directions[i]->y, x->dist + 1);
                adj->moves = x->moves;
                adj->moves.push_back(directions[i]->name);
                visited[adj->row][adj->col] = 1;
                q.push(adj);
            }
        }
        return {};
    }
};

int main() {
    string curPos, tarPos;
    cin >> curPos >> tarPos;
    Solution obj;
    GraphNode* ans = obj.minStepToReachTarget({curPos[0]-'a', curPos[1]-'1'}, {tarPos[0]-'a', tarPos[1]-'1'}, 8);
    cout << ans->moves.size() << endl;
    for (auto &ele : ans->moves) cout << ele << endl;
    return 0;
}

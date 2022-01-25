#include <vector>
using namespace std;

class Solution {
    bool bipartite = true;
    vector<int> visited;
    vector<int> clr;

    void dfs(int& node, int col, vector<vector<int>>& graph) {
        if (visited[node]) {
            if (col != clr[node]) bipartite = false;
            return;
        }
        visited[node] = true;
        clr[node] = col;
        int adjColor = (col == 0) ? 1 : 0;
        for (int i{0}; i<graph[node].size(); i++) dfs(graph[node][i], adjColor, graph);
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int ndsCnt = graph.size();
        if (!ndsCnt) return true;
        visited.resize(ndsCnt, 0);
        clr.resize(ndsCnt, -1);
        for (int i{0}; i<ndsCnt; i++) if (!visited[i]) dfs(i, 1, graph);
        return bipartite;
    }
};

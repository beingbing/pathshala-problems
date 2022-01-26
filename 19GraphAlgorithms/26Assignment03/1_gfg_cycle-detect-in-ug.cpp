#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void dfs(int node, int prvNode, vector<bool>& visited, bool& hasCycle, vector<int> adj[]) {
        if (visited[node]) {
            hasCycle = true;
            return;
        }
        visited[node] = true;
        for (int i{0}; i<adj[node].size(); i++) {
            if (adj[node][i] == prvNode) continue;
            dfs(adj[node][i], node, visited, hasCycle, adj);
        }
    }

public:
    bool isCycle(int n, vector<int> adj[]) {
        vector<bool> visited(n, false);
        bool hasCycle = false;
        for (int i{0}; i<n; i++) if (!visited[i]) dfs(i, -1, visited, hasCycle, adj);
        return hasCycle;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}

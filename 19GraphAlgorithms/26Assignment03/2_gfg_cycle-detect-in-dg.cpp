#include <iostream>
#include <vector>
using namespace std;

class Solution {

    void dfs(int node, vector<int>& visited, bool& hasCycle, vector<int> adj[]) {
        if (visited[node]) {
            if (visited[node] == 1) hasCycle = true;
            return;
        }
        visited[node] = 1;
        for (int i{0}; i < adj[node].size(); i++) dfs(adj[node][i], visited, hasCycle, adj);
        visited[node] = 2;
    }
public:
    bool isCyclic(int n, vector<int> adj[]) {
        vector<int> visited(n, false);
        bool hasCycle = false;
        for (int i{0}; i<n; i++) if (!visited[i]) dfs(i, visited, hasCycle, adj);
        return hasCycle;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }
    return 0;
}

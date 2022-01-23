#include <iostream>
#include <vector>
using namespace std;

class Solution {

    void dfs(int node, vector<int>& visited, vector<int>& ans, vector<int> adj[]) {
        if (visited[node]) return;
        visited[node] = 1;
        ans.push_back(node);
        for (int i{0}; i < adj[node].size(); i++)
            dfs(adj[node][i], visited, ans, adj);
    }

public:
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<int> ans;
        vector<int> visited(v);
        for (int i{0}; i < v; i++) dfs(i, visited, ans, adj);
        return ans;
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
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}

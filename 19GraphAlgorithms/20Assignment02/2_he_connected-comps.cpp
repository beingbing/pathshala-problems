#include <iostream>
#include <vector>
using namespace std;

class Solution {

    void dfs(int node, vector<int>& visited, vector<vector<int>>& adj) {
        if (visited[node]) return;
        visited[node] = 1;
        for (int i{0}; i < adj[node].size(); i++)
            dfs(adj[node][i], visited, adj);
    }

public:
    int componentsCnt(int& nodesCnt, vector<vector<int>>& adj) {
        int ans{0};
        vector<int> visited(nodesCnt+1);
        for (int i{1}; i <= nodesCnt; i++) if (!visited[i]) ans++, dfs(i, visited, adj);
        return ans;
    }
};

int main() {
        int n, e;
        cin >> n >> e;
        vector<vector<int>> adj(n+1);
        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        int ans = obj.componentsCnt(n, adj);
        cout << ans << endl;
    return 0;
}

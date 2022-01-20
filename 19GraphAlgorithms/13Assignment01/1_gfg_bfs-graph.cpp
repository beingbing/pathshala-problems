#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> bfsOfGraph(int nodesCnt, vector<int> adj[]) {
        vector<int> visited(nodesCnt+1, 0), ans;
        queue<int> q;
        visited[0] = 1;
        q.push(0);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for (int i{0}; i<adj[x].size(); i++) {
                if (visited[adj[x][i]]) continue;
                visited[adj[x][i]] = 1;
                q.push(adj[x][i]);
            }
        }
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
        }
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}

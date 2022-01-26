#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int n, vector<int> adj[]) {
        vector<int> indegree(n, 0);
        for (int i{0}; i<n; i++) for (int j{0}; j< adj[i].size(); j++) indegree[adj[i][j]]++;
        queue<int> possibleNodes;
        for (int i{0}; i<n; i++) if (indegree[i] == 0) possibleNodes.push(i);
        vector<int> topologicalOrder;
        while (!possibleNodes.empty()) {
            int x = possibleNodes.front();
            possibleNodes.pop();
            topologicalOrder.push_back(x);
            for (int j{0}; j<adj[x].size(); j++) {
                indegree[adj[x][j]]--;
                if(indegree[adj[x][j]] == 0) possibleNodes.push(adj[x][j]);
            }
        }
        return topologicalOrder;
    }
};

int check(int V, vector<int> &res, vector<int> adj[]) {
    if (V != res.size()) return 0;
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) map[res[i]] = i;
    for (int i = 0; i < V; i++) for (int v : adj[i]) if (map[i] > map[v]) return 0;
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        Solution obj;
        vector<int> res = obj.topoSort(N, adj);
        cout << check(N, res, adj) << endl;
    }
    return 0;
}

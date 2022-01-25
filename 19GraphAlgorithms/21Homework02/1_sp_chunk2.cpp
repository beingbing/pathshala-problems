#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> primes(1300001, 1);
vector<int> nthPrime;

void primesTill() {
	primes[0] = 0;
    primes[1] = 0;
    int val = sqrt(1300001);
    for (int i{2}; i<=val; i++)
        if (primes[i] == 1)
            for (int j=i; i*j<=1300001; j++) primes[i*j] = 0;
}

class Solution {
    int cnt{0};

    void dfs(int node, vector<int>& visited, vector<vector<int>>& adj) {
        if (visited[node]) return;
        visited[node] = 1;
        cnt++;
        for (int i{0}; i < adj[node].size(); i++)
            dfs(adj[node][i], visited, adj);
    }

public:
    int largestComponentSize(int& nodesCnt, vector<vector<int>>& adj) {
        int ans{0};
        vector<int> visited(nodesCnt+1);
        for (int i{1}; i <= nodesCnt; i++) if (!visited[i]) dfs(i, visited, adj), ans = max(ans, cnt), cnt = 0;
        return ans;
    }
};

int main() {
    primesTill();
    nthPrime.push_back(-1);
    for (int i{0}; i<1300001; i++) if (primes[i]) nthPrime.push_back(i);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (!m) {
            cout << -1 << endl;
            continue;
        }
        vector<vector<int>> adj(n+1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        int ans = obj.largestComponentSize(n, adj);
        cout << nthPrime[ans] << endl;
    }
    return 0;
}

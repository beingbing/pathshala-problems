#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Graph {
    vector<vector<int>> adjList;
    vector<int> visited, dist;

public:
    Graph(int n) {
        adjList.resize(n);
        visited.resize(n, 0);
        dist.resize(n, -1);
    }

    void add_edge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> shortest_reach(int start) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        dist[start] = 0;
        visited[start] = 1;
        while (!q.empty()) {
            pair<int, int> x = q.front(); // x = nextNode
            q.pop();
            for (int i{0}; i < adjList[x.first].size(); i++) {
                if (visited[adjList[x.first][i]]) continue;
                visited[adjList[x.first][i]] = 1;
                dist[adjList[x.first][i]] = x.second + 6;
                q.push({adjList[x.first][i], x.second + 6});
            }
        }
        return dist;
    }
};

int main() {
    int queries;
    cin >> queries;
    for (int t = 0; t < queries; t++) {
        int n, m;
        cin >> n;
        Graph graph(n);
        cin >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph.add_edge(u, v);
        }
        int startId;
        cin >> startId;
        startId--;
        vector<int> distances = graph.shortest_reach(startId);
        for (int i = 0; i < distances.size(); i++) if (i != startId) cout << distances[i] << " ";
        cout << endl;
    }
    return 0;
}

~~ shortest path in an undirected graph ~~

given an unweighted undirected graph, given a src, find the shortest path to all the other destinations.

shortest path => number of edges between the two nodes must be minimum.

          {node, dist}
queue<pair<int, int>> q;
int visited[n+1];
int src;
vector<int> adj[n+1];
vector<int> dist(n+1, INF);
q.push({src, 0});
dist[src] = 0;
while (!q.empty()) {
    pair<int, int> x = q.front(); // x = nextNode
    q.pop();
    for (i{0}; i<adj[x.first]; i++) {
        if (!visited[adj[x.first][i]]) visited[adj[x.first][i]] = 1;
        dist[adj[x.first][i]] = x.second+1;
        q.push({adj[x.first][i], x.second+1});
    }
}

shortest path in case of unweighted graph can always be computed by BFS.

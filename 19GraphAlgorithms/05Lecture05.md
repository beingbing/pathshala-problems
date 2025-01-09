~~ breadth first search (BFS) ~~

BFS is similar to level order traversal in tree.

here, we need to maintain a list of visited nodes, which similar to level-order traversal will be
a queue and an array to maintain visited nodes.

here, first we visit a node, then we visit its neighbour. or in other words, from the node with which
we start, we first visit the nodes which are one jump away, then nodes which are two jumps away and it
goes on...

void bfs(src) {
    vector<int> visited(n+1, 0);
    vector<int> adj(n+1);
    queue<int> q;
    visited[src] = 1;
    q.push(src);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        print(x);
        for (int i{0}; i<adj[x].size(); i++) {
            if (visited[adj[x][i]]) continue;
            visited[adj[x][i]] = 1;
            q.push(adj[x][i]);
        }
    }
}
TC = O(v+2e) ~~ O(v+e)
SC = O(v)

Q. what if there are disconnected components ?
A. in that case make visited array global and then check for every node.

int main() {
    for (i{1}; i<=n; i++) bfs(i);
}

vector<int> visited(n+1, 0);
vector<int> adj(n+1);

void bfs(src) {
    queue<int> q;
    visited[src] = 1;
    q.push(src);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        print(x);
        for (int i{0}; i<adj[x].size(); i++) {
            if (visited[adj[x][i]]) continue;
            visited[adj[x][i]] = 1;
            q.push(adj[x][i]);
        }
    }
}

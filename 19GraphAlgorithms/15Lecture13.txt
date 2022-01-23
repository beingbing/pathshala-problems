~~ depth first search ~~

DFS is a recursion based traversal.

when you recurse for a particular node, you only return back only when you have visited all the nodes
connected to it.

vector<int> adj[n+1];
int visited[n+1] = {0};
void dfs(int node) {
    if (visited[node]) return;
    visited[node] = 1;
    print(node);
    for (int i{0}; i<adj[node].size(); i++) {
        dfs(adj[node][i]);
    }
}

if there are multiple components of graphs, then to visit all the nodes,
run a loop and call dfs()

for (int i{0}; i<n; i++) dfs(i);

SC = O(n)
TC = O(n+e)

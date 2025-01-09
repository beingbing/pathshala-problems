# Breadth-First Search (BFS)

**Breadth-First Search (BFS)** is a graph traversal algorithm that explores nodes layer by layer, akin to level-order traversal in trees. It starts at a source node and visits all nodes at the current depth level before moving to nodes at the next depth level.

## Key Features of BFS
1. **Traversal Order:** BFS starts from the source node and first visits all nodes one edge away (one "jump"), followed by nodes two edges away, and so on.

2. **Data Structures Used:**
    - A **queue** is used to maintain the nodes to be visited.
    - A **visited array** ensures each node is processed only once.

## Complexity:
- **Time:** O(V + E) where V = number of nodes, E = number of edges.
- **Space:** O(V) (for visited array and queue)

## Code
```java
import java.util.*;

class Graph {
    private int nodes;
    private List<List<Integer>> adjList;

    public Graph(int nodes) {
        this.nodes = nodes;
        adjList = new ArrayList<>();
        for (int i = 0; i < nodes; i++) {
            adjList.add(new ArrayList<>());
        }
    }

    public void addEdge(int u, int v) {
        adjList.get(u).add(v);
        adjList.get(v).add(u); // For undirected graph
    }

    public void bfs(int src) {
        boolean[] visited = new boolean[nodes];
        Queue<Integer> queue = new LinkedList<>();
        visited[src] = true;
        queue.add(src);

        while (!queue.isEmpty()) {
            int node = queue.poll();
            System.out.print(node + " ");

            for (int neighbor : adjList.get(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.add(neighbor);
                }
            }
        }
    }
}

public class BFSConnected {
    public static void main(String[] args) {
        Graph graph = new Graph(5);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 3);
        graph.addEdge(1, 4);

        System.out.println("BFS Traversal starting from node 0:");
        graph.bfs(0);
    }
}
```

### Handling Disconnected Graphs
In disconnected graphs, BFS may not visit all nodes if started from a single source. To handle this, iterate through all nodes and initiate BFS for each unvisited node.

```java
class GraphDisconnected {
    private int nodes;
    private List<List<Integer>> adjList;

    public GraphDisconnected(int nodes) {
        this.nodes = nodes;
        adjList = new ArrayList<>();
        for (int i = 0; i < nodes; i++) {
            adjList.add(new ArrayList<>());
        }
    }

    public void addEdge(int u, int v) {
        adjList.get(u).add(v);
        adjList.get(v).add(u); // For undirected graph
    }

    public void bfsDisconnected() {
        boolean[] visited = new boolean[nodes];
        for (int i = 0; i < nodes; i++) {
            if (!visited[i]) {
                bfs(i, visited);
            }
        }
    }

    private void bfs(int src, boolean[] visited) {
        Queue<Integer> queue = new LinkedList<>();
        visited[src] = true;
        queue.add(src);

        while (!queue.isEmpty()) {
            int node = queue.poll();
            System.out.print(node + " ");

            for (int neighbor : adjList.get(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.add(neighbor);
                }
            }
        }
    }
}

public class BFSDisconnectedExample {
    public static void main(String[] args) {
        GraphDisconnected graph = new GraphDisconnected(6);
        graph.addEdge(0, 1);
        graph.addEdge(2, 3);
        graph.addEdge(4, 5);

        System.out.println("BFS Traversal for a disconnected graph:");
        graph.bfsDisconnected();
    }
}
```

---

### Key Considerations
1. **Multiple Components:** For disconnected graphs, ensure all components are traversed by iterating over all nodes.
2. **Edge Weight:** BFS doesn't account for edge weights. Use algorithms like Dijkstra's if weights matter.
3. **Undirected vs Directed Graphs:** The logic remains the same, but edge representation differs.

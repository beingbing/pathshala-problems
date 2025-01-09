# Depth First Search (DFS)

**Depth First Search (DFS)** is a graph traversal algorithm that explores as far as possible along each branch before backtracking. It is a **recursion-based traversal** method and operates in a depth-wise manner.

## Key Features of DFS
1. **Traversal Order:**  
   DFS starts from a source node and explores a path until no further nodes can be visited, then backtracks to explore other unvisited paths.

2. **Implementation:**  
   DFS is typically implemented using recursion, but it can also be implemented iteratively using a stack.

3. **Components in DFS:**
    - A **visited array** ensures nodes are not revisited.
    - Recursive calls explore the graph.

4. **Handling Multiple Components:**  
   To traverse all components in a disconnected graph, iterate through all nodes and call DFS for each unvisited node.

5. **Time Complexity:** O(V + E) where V = number of nodes, E = number of edges.

6. **Space Complexity:** O(V) (for the visited array and recursion stack).

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

    // Recursive DFS
    private void dfs(int node, boolean[] visited) {
        if (visited[node]) return;

        visited[node] = true;
        System.out.print(node + " ");

        for (int neighbor : adjList.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }

    // Driver for DFS
    public void dfsTraversal(int startNode) {
        boolean[] visited = new boolean[nodes];
        dfs(startNode, visited);
    }
}

public class DFSConnected {
    public static void main(String[] args) {
        Graph graph = new Graph(5);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 3);
        graph.addEdge(1, 4);

        System.out.println("DFS Traversal starting from node 0:");
        graph.dfsTraversal(0);
    }
}
```

---

#### DFS for a Disconnected Graph:

In a disconnected graph, DFS must be invoked for all components to ensure all nodes are visited.

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

    // Recursive DFS
    private void dfs(int node, boolean[] visited) {
        if (visited[node]) return;

        visited[node] = true;
        System.out.print(node + " ");

        for (int neighbor : adjList.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }

    // Driver for DFS in disconnected graph
    public void dfsDisconnected() {
        boolean[] visited = new boolean[nodes];
        for (int i = 0; i < nodes; i++) {
            if (!visited[i]) {
                dfs(i, visited);
            }
        }
    }
}

public class DFSDisconnectedExample {
    public static void main(String[] args) {
        GraphDisconnected graph = new GraphDisconnected(6);
        graph.addEdge(0, 1);
        graph.addEdge(2, 3);
        graph.addEdge(4, 5);

        System.out.println("DFS Traversal for a disconnected graph:");
        graph.dfsDisconnected();
    }
}
```

---

### Key Observations:
1. **Recursion Depth:** DFS can cause stack overflow for large graphs. Use an iterative stack-based approach if necessary.
2. **Backtracking:** DFS naturally backtracks when no unvisited neighbors remain for the current node.
3. **Applications:**  
   - **Cycle detection** in graphs.
   - **Pathfinding** and **connected components** detection.
   - **Topological sorting** for directed acyclic graphs (DAGs).

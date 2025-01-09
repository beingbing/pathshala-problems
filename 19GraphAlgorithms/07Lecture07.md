# Shortest Path in an Unweighted Undirected Graph
In an **unweighted undirected graph**, the **shortest path** between two nodes is defined as the **minimum number of edges** required to traverse between them. **BFS** is the optimal algorithm to compute the shortest path in such cases because it explores all nodes at the current depth before moving to the next.

### Complexity:
- Time: O(V + E), where V = number of nodes, E = number of edges.
- Space: O(V) (for visited and distance arrays, and the queue).

### Code
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

    // Compute shortest path using BFS
    public void bfsShortestPath(int src) {
        int[] dist = new int[nodes];
        Arrays.fill(dist, Integer.MAX_VALUE); // Initialize distances to infinity
        boolean[] visited = new boolean[nodes];

        Queue<Integer> queue = new LinkedList<>();
        queue.add(src);
        dist[src] = 0; // Distance from src to itself is 0
        visited[src] = true;

        while (!queue.isEmpty()) {
            int node = queue.poll();

            for (int neighbor : adjList.get(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    dist[neighbor] = dist[node] + 1; // Update shortest distance
                    queue.add(neighbor);
                }
            }
        }

        // Print shortest distances from src
        System.out.println("Shortest distances from node " + src + ":");
        for (int i = 0; i < nodes; i++) {
            System.out.println("To node " + i + ": " + dist[i]);
        }
    }
}

public class BFSShortestPath {
    public static void main(String[] args) {
        Graph graph = new Graph(6);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 3);
        graph.addEdge(1, 4);
        graph.addEdge(2, 5);

        System.out.println("Shortest path in BFS tree:");
        graph.bfsShortestPath(0);
    }
}
```

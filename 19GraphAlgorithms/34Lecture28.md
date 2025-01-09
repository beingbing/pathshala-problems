# Articulation Points
An **articulation point** (or cut vertex) in an undirected graph is a vertex that, if removed along with its edges, increases the number of connected components in the graph.

### **Properties of Articulation Points**
1. **Single Connected Component to Multiple Components**: Removing an articulation point splits the graph into multiple disconnected subgraphs.
2. **Applications**:
    - Network design: Identifying weak points in networks.
    - Road/Bridge analysis: Finding critical roads/bridges in transportation systems.
    - Dependency resolution: Detecting bottlenecks in software dependencies.

### **Identifying Articulation Points**
For a vertex `u` to be an articulation point:
1. **Root Node in DFS Tree**:
    - If `u` is the root of the DFS tree, it is an articulation point if it has two or more children in the DFS tree.
2. **Non-Root Node**:
    - `u` is an articulation point if it has a child `v` such that no vertex in the subtree rooted at `v` has a back edge to any ancestor of `u`.

This condition is formalized using the **DFS Low-Link Value**:
- **Discovery Time (disc[u])**: The time when a vertex `u` is first visited during DFS.
- **Low-Link Value (low[u])**: The smallest discovery time reachable from `u` or its descendants, including back edges.

#### **Conditions for Articulation Point**
- If `u` is the root of the DFS tree and has two or more children.
- If `u` is not the root and `low[v] >= disc[u]` for any child `v`.

---

### **Algorithm to Find Articulation Points**

1. Perform a DFS on the graph.
2. Maintain `disc[]`, `low[]`, `parent[]`, and a boolean array `isArticulation[]`.
3. During DFS:
    - Update \( low[u] \) based on children and back edges.
    - Check the conditions for \( u \) to be an articulation point.

#### **Time Complexity**
- \( O(V + E) \): Linear in the number of vertices and edges.

---

### **Implementation in Java**

```java
import java.util.*;

class ArticulationPoints {
    private int vertices;
    private List<List<Integer>> graph;
    private int time;
    private int[] disc, low, parent;
    private boolean[] visited, isArticulation;

    public ArticulationPoints(int vertices) {
        this.vertices = vertices;
        graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) {
            graph.add(new ArrayList<>());
        }
        disc = new int[vertices];
        low = new int[vertices];
        parent = new int[vertices];
        visited = new boolean[vertices];
        isArticulation = new boolean[vertices];
        Arrays.fill(disc, -1); // Unvisited
        Arrays.fill(parent, -1); // No parent initially
    }

    public void addEdge(int u, int v) {
        graph.get(u).add(v);
        graph.get(v).add(u); // Undirected graph
    }

    private void dfs(int u) {
        visited[u] = true;
        disc[u] = low[u] = ++time; // Initialize discovery and low values
        int children = 0; // Count of children in DFS tree

        for (int v : graph.get(u)) {
            if (!visited[v]) { // If v is not visited
                parent[v] = u;
                children++;
                dfs(v);

                // Update low value of u for the subtree
                low[u] = Math.min(low[u], low[v]);

                // Check if u is an articulation point
                if (parent[u] == -1 && children > 1) { // Root node
                    isArticulation[u] = true;
                }
                if (parent[u] != -1 && low[v] >= disc[u]) { // Non-root node
                    isArticulation[u] = true;
                }
            } else if (v != parent[u]) { // Back edge
                low[u] = Math.min(low[u], disc[v]);
            }
        }
    }

    public List<Integer> findArticulationPoints() {
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        List<Integer> articulationPoints = new ArrayList<>();
        for (int i = 0; i < vertices; i++) {
            if (isArticulation[i]) {
                articulationPoints.add(i);
            }
        }
        return articulationPoints;
    }

    public static void main(String[] args) {
        ArticulationPoints graph = new ArticulationPoints(5);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 2);
        graph.addEdge(1, 3);
        graph.addEdge(3, 4);

        List<Integer> articulationPoints = graph.findArticulationPoints();
        System.out.println("Articulation Points: " + articulationPoints);
    }
}
```

---

### **Example**

#### Graph:
```
0 -- 1 -- 3 -- 4
 \   |
   \ 2
```

#### Steps:
1. Perform DFS:
    - Discovery times and low-link values:
      ```
      Vertex: 0  1  2  3  4
      Disc:   1  2  3  4  5
      Low:    1  2  3  4  5
      ```

2. Identify articulation points:
    - Vertex \(1\) is an articulation point because removing it disconnects \(0, 2\) from \(3, 4\).
    - Vertex \(3\) is an articulation point because removing it disconnects \(4\).

#### Output:
```
Articulation Points: [1, 3]
```

---

### **Key Features**
1. Works for **connected** and **disconnected** graphs.
2. DFS-based implementation is efficient and intuitive.

### **Edge Cases**
1. A single vertex graph has no articulation points.
2. A fully connected graph (clique) has no articulation points.

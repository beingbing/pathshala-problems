# Strongly Connected Components

## Connected Component
A sub-graph of a graph where every node is reachable from every other node.

## Strongly Connected Components (SCC) Definition
A **Strongly Connected Component (SCC)** of a directed graph is a maximal subgraph where every vertex is reachable from every other vertex in the subgraph.

### Properties of SCC
1. A graph can be decomposed into a **Directed Acyclic Graph (DAG)** of its SCCs.

### **Applications of SCC**
1. **Deadlock Detection**: Analyze resource allocation graphs.
2. **Web Crawling**: Detect groups of pages that are interlinked.
3. **Optimization**: Decompose problems in circuits or networks.
4. **Social Networks**: Identify communities where users are mutually reachable.

## **Kosaraju's Algorithm**
Kosaraju's algorithm is a popular method to find SCCs in a directed graph. It uses **DFS** twice and is based on the idea of graph reversal.

### **Steps**
1. Perform a **DFS** on the original graph, storing the vertices in a **stack** based on their finish time (finishing a vertex after all its descendants are visited).
2. Reverse the graph (reverse all edges).
3. Perform DFS again on the reversed graph, visiting vertices in the order determined by the stack.
4. Each DFS tree in this pass represents one SCC.

### **Time Complexity**
- `O(V + E)`: Linear in the number of vertices and edges.

### **Implementation: Kosaraju's Algorithm in Java**

```java
import java.util.*;

class KosarajuSCC {
    private int vertices;
    private List<List<Integer>> graph;
    private List<List<Integer>> reversedGraph;

    public KosarajuSCC(int vertices) {
        this.vertices = vertices;
        graph = new ArrayList<>();
        reversedGraph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) {
            graph.add(new ArrayList<>());
            reversedGraph.add(new ArrayList<>());
        }
    }

    public void addEdge(int u, int v) {
        graph.get(u).add(v);
    }

    private void reverseGraph() {
        for (int u = 0; u < vertices; u++) {
            for (int v : graph.get(u)) {
                reversedGraph.get(v).add(u);
            }
        }
    }

    private void dfs1(int node, boolean[] visited, Stack<Integer> stack) {
        visited[node] = true;
        for (int neighbor : graph.get(node)) {
            if (!visited[neighbor]) {
                dfs1(neighbor, visited, stack);
            }
        }
        stack.push(node);
    }

    private void dfs2(int node, boolean[] visited, List<Integer> component) {
        visited[node] = true;
        component.add(node);
        for (int neighbor : reversedGraph.get(node)) {
            if (!visited[neighbor]) {
                dfs2(neighbor, visited, component);
            }
        }
    }

    public List<List<Integer>> findSCCs() {
        Stack<Integer> stack = new Stack<>();
        boolean[] visited = new boolean[vertices];

        // Step 1: DFS on the original graph to fill the stack
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                dfs1(i, visited, stack);
            }
        }

        // Step 2: Reverse the graph
        reverseGraph();

        // Step 3: DFS on the reversed graph in the order of the stack
        Arrays.fill(visited, false);
        List<List<Integer>> sccs = new ArrayList<>();
        while (!stack.isEmpty()) {
            int node = stack.pop();
            if (!visited[node]) {
                List<Integer> component = new ArrayList<>();
                dfs2(node, visited, component);
                sccs.add(component);
            }
        }

        return sccs;
    }

    public static void main(String[] args) {
        KosarajuSCC graph = new KosarajuSCC(5);
        graph.addEdge(0, 2);
        graph.addEdge(2, 0);
        graph.addEdge(1, 0);
        graph.addEdge(0, 3);
        graph.addEdge(3, 4);

        List<List<Integer>> sccs = graph.findSCCs();
        System.out.println("Strongly Connected Components:");
        for (List<Integer> component : sccs) {
            System.out.println(component);
        }
    }
}
```

---

### **Example**

Consider the graph:
```
0 → 2 → 3 → 4
↑    ↓    
1 ←  0
```

#### Steps (Kosaraju's Algorithm)
1. Perform DFS on the original graph:
    - Finish order: \( [4, 3, 2, 0, 1] \).

2. Reverse the graph:
    - Reversed edges: \( 2 → 0, 0 → 1, 0 → 2, 3 → 0, 4 → 3 \).

3. Perform DFS on the reversed graph:
    - Components: \( [4], [3], [0, 2, 1] \).

### **Tarjan's Algorithm**
Tarjan's algorithm finds SCCs in a single DFS traversal using **low-link values**.

#### **Concepts**
- **Discovery Time**: The time when a vertex is first visited.
- **Low-Link Value**: The smallest discovery time reachable from the vertex or its descendants.

#### **Steps**
1. Perform a DFS, keeping track of discovery times and low-link values.
2. Use a stack to maintain vertices of the current DFS path.
3. When a vertex's low-link value equals its discovery time, it is the root of an SCC. Pop all vertices in the stack up to this vertex.

#### **Time Complexity**
- `O(V + E)`: Linear in the number of vertices and edges.

### **Implementation: Tarjan's Algorithm in Java**

```java
import java.util.*;

class TarjanSCC {
    private int vertices;
    private List<List<Integer>> graph;
    private int time;
    private int[] low, disc;
    private boolean[] onStack;
    private Stack<Integer> stack;
    private List<List<Integer>> sccs;

    public TarjanSCC(int vertices) {
        this.vertices = vertices;
        graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) {
            graph.add(new ArrayList<>());
        }
        time = 0;
        low = new int[vertices];
        disc = new int[vertices];
        onStack = new boolean[vertices];
        stack = new Stack<>();
        sccs = new ArrayList<>();
        Arrays.fill(disc, -1); // Unvisited
    }

    public void addEdge(int u, int v) {
        graph.get(u).add(v);
    }

    private void dfs(int u) {
        disc[u] = low[u] = time++;
        stack.push(u);
        onStack[u] = true;

        for (int v : graph.get(u)) {
            if (disc[v] == -1) { // If v is not visited
                dfs(v);
                low[u] = Math.min(low[u], low[v]);
            } else if (onStack[v]) { // Back edge
                low[u] = Math.min(low[u], disc[v]);
            }
        }

        // If u is a root of an SCC
        if (low[u] == disc[u]) {
            List<Integer> component = new ArrayList<>();
            int v;
            do {
                v = stack.pop();
                onStack[v] = false;
                component.add(v);
            } while (v != u);
            sccs.add(component);
        }
    }

    public List<List<Integer>> findSCCs() {
        for (int i = 0; i < vertices; i++) {
            if (disc[i] == -1) {
                dfs(i);
            }
        }
        return sccs;
    }

    public static void main(String[] args) {
        TarjanSCC graph = new TarjanSCC(5);
        graph.addEdge(0, 2);
        graph.addEdge(2, 0);
        graph.addEdge(1, 0);
        graph.addEdge(0, 3);
        graph.addEdge(3, 4);

        List<List<Integer>> sccs = graph.findSCCs();
        System.out.println("Strongly Connected Components:");
        for (List<Integer> component : sccs) {
            System.out.println(component);
        }
    }
}
```

---

Both **Kosaraju's** and **Tarjan's** algorithms are efficient and widely used for finding SCCs. Choose based on simplicity or specific constraints of your problem!

## Example:
### Problem:
Given a directed graph, count all SCC.

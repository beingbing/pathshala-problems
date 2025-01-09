# Minimum Spanning Tree
A **Minimum Spanning Tree (MST)** is a subset of the edges of a weighted, connected, and undirected graph that:
1. **Connects all vertices** in the graph.
2. Forms a tree (i.e., no cycles).
3. Minimizes the total edge weight.

## Properties of MST
1. A graph with `V` vertices will have `V-1` edges in the MST.
2. There may be multiple MSTs for the same graph if edges have the same weight.
3. MST exists only if the graph is connected; otherwise, we cannot span all vertices.

### Applications of MST
1. Network Design: Design of communication, electrical, and transportation networks.
2. Approximation Algorithms: Used in algorithms for NP-hard problems like the Traveling Salesman Problem.
3. Clustering: MST is used in hierarchical clustering.

## Kruskal's Algorithm
Kruskal's Algorithm is one of the most popular algorithms for finding the MST. It is a **greedy algorithm** that adds edges in increasing order of weight while avoiding cycles.

### Steps of Kruskal's Algorithm
1. **Sort all edges** in non-decreasing order of their weight.
2. Initialize an empty data structure for MST and a **disjoint set union (DSU)** structure to keep track of connected components.
3. For each edge (in sorted order):
    - If adding the edge doesn’t form a cycle (i.e., the two vertices of the edge are in different sets):
        - Add the edge to the MST.
        - Union the two sets in the DSU.
4. Stop when the MST contains `V-1` edges.

#### Time Complexity
- Sorting the edges: `O(E log E)`
- DSU operations for each edge: `O(E * log(V))`
- Overall: `O(E log E)`.

### Implementation of Kruskal's Algorithm in Java
```java
import java.util.*;

class KruskalMST {
    static class Edge implements Comparable<Edge> {
        int src, dest, weight;

        public Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }

        // Compare edges by weight
        public int compareTo(Edge other) {
            return this.weight - other.weight;
        }
    }

    static class DisjointSetUnion {
        private int[] parent, rank;

        public DisjointSetUnion(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        public int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        }

        public void union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }
    }

    public static int kruskalMST(int n, List<Edge> edges) {
        Collections.sort(edges); // Sort edges by weight

        DisjointSetUnion dsu = new DisjointSetUnion(n);
        int mstWeight = 0;
        List<Edge> mstEdges = new ArrayList<>();

        for (Edge edge : edges) {
            int root1 = dsu.find(edge.src);
            int root2 = dsu.find(edge.dest);

            // If adding this edge doesn't form a cycle
            if (root1 != root2) {
                mstEdges.add(edge);
                mstWeight += edge.weight;
                dsu.union(root1, root2);
            }

            // Stop when we have V-1 edges in the MST
            if (mstEdges.size() == n - 1) break;
        }

        // Print the MST edges
        System.out.println("Edges in the MST:");
        for (Edge edge : mstEdges) {
            System.out.println(edge.src + " -- " + edge.dest + " == " + edge.weight);
        }

        return mstWeight;
    }

    public static void main(String[] args) {
        int n = 4; // Number of vertices
        List<Edge> edges = Arrays.asList(
            new Edge(0, 1, 10),
            new Edge(0, 2, 6),
            new Edge(0, 3, 5),
            new Edge(1, 3, 15),
            new Edge(2, 3, 4)
        );

        int mstWeight = kruskalMST(n, edges);
        System.out.println("Total weight of MST: " + mstWeight);
    }
}
```

### **Example**
#### Problem:
Given n cities in the form of undirected, weighted and connected graph. Construct the roads such that all the cities forms a connected component and cost of construction must be minimum. Given below are the current edges of the cities -
```
0 --(4)-- 1
1 --(8)-- 2
2 --(7)-- 3
3 --(9)--4
4 --(10)-- 5
5 --(2)-- 6
6 --(1)-- 7
7 --(8)-- 0
7 --(11)-- 1
7 --(7)-- 8
2 --(2)-- 8
6 --(6)-- 8
2 --(4)-- 5
3 --(14)-- 5
```

#### Steps:
1. **Sort edges by weight**:
    - `(2,3,4), (0,3,5), (0,2,6), (0,1,10), (1,3,15)`
2. Process edges in sorted order:
    - Add `(2,3,4)`: No cycle.
    - Add `(0,3,5)`: No cycle.
    - Add `(0,1,10)`: No cycle.
    - Stop as we now have `V-1 = 3` edges.

#### MST:
Edges: `(2,3,4)`, `(0,3,5)`, `(0,1,10)`  
Total weight: `4 + 5 + 10 = 19`.

### Key Features of Kruskal's Algorithm
- **Flexibility**: Works on any connected, undirected graph.
- **Efficiency**: `O(E log E)` due to sorting.
- **DSU Integration**: Efficiently handles the cycle-checking requirement.

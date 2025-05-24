# 🚀 **Dijkstra's Algorithm**
Let’s **dive deep into Dijkstra's Algorithm** – one of the most fundamental graph algorithms used for finding **shortest paths** from a **source vertex** to all other vertices in a **weighted graph with non-negative edge weights**.

## 🔸 **What is it?**
Dijkstra’s Algorithm finds the **shortest path** from a **source node** to **all other nodes** in a **graph** (or optionally, a destination node).

### 🌟 **Key Assumptions**:
* The graph is **weighted** (with weights representing costs, distances, etc.).
* **All edge weights are non-negative** (if negative weights exist, use Bellman-Ford instead).

## 🔸 **Why Dijkstra Works?**
The algorithm **greedily** selects the node with the **smallest tentative distance** (current best known shortest distance from the source) and updates distances to its neighbors.

It works because with **non-negative weights**, once we’ve found the shortest path to a node, no shorter path will ever appear later.

## 🧠 **Intuition** (Imagine Driving in a City)
- Start at your **source city**. 
- Check all **neighboring cities** and record how far they are. 
- Pick the **nearest city** (lowest total distance so far).
- Update distances to its neighbors (new shorter routes may be found).
- Repeat until you’ve visited all cities.

## 🔎 **Detailed Algorithm**
1. **Initialization**:
    * Set distance to the **source node** as 0, all others as **infinity**.
    * Mark all nodes as **unvisited**.
    * Use a **priority queue (min-heap)** to always pick the next closest node.

2. **Relaxation Step**:
    * For each **neighbor** of the current node $u$:
        * If $\text{distance}[u] + \text{weight}(u,v) < \text{distance}[v]$, update $\text{distance}[v]$.

3. **Repeat**:
    * Pick the **unvisited node with the smallest distance**.
    * Mark it **visited** and repeat the relaxation.

4. **End**:
    * When all nodes are visited or the priority queue is empty.

## 🖥 **Java Implementation (PriorityQueue)**
```java
import java.util.*;

class Dijkstra {
    static class Edge {
        int to, weight;
        Edge(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }

    static class Node implements Comparable<Node> {
        int vertex, dist;
        Node(int vertex, int dist) {
            this.vertex = vertex;
            this.dist = dist;
        }

        public int compareTo(Node other) {
            return this.dist - other.dist;
        }
    }

    public static int[] dijkstra(int n, List<List<Edge>> graph, int source) {
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[source] = 0;

        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(source, 0));

        while (!pq.isEmpty()) {
            Node current = pq.poll();
            int u = current.vertex;

            for (Edge edge : graph.get(u)) {
                int v = edge.to;
                int weight = edge.weight;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.offer(new Node(v, dist[v]));
                }
            }
        }

        return dist;
    }

    public static void main(String[] args) {
        int n = 5;
        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());

        // Example Graph
        graph.get(0).add(new Edge(1, 10));
        graph.get(0).add(new Edge(4, 5));
        graph.get(1).add(new Edge(2, 1));
        graph.get(1).add(new Edge(4, 2));
        graph.get(2).add(new Edge(3, 4));
        graph.get(3).add(new Edge(2, 6));
        graph.get(3).add(new Edge(0, 7));
        graph.get(4).add(new Edge(1, 3));
        graph.get(4).add(new Edge(2, 9));
        graph.get(4).add(new Edge(3, 2));

        int source = 0;
        int[] distances = dijkstra(n, graph, source);

        System.out.println("Shortest distances from node " + source + ":");
        for (int i = 0; i < n; i++) {
            System.out.println("To node " + i + " = " + distances[i]);
        }
    }
}
```

## 🧮 **Time Complexity**
* Using **PriorityQueue (binary heap)**:
  $$
  O((V + E) \log V)
  $$
  where $V$ is vertices, $E$ is edges.

* With a simple array instead of a heap (inefficient for sparse graphs):
  $$
  O(V^2)
  $$

## 📝 **Key Properties**
✅ Works with **non-negative edge weights**
✅ Finds the **single-source shortest paths**
✅ Builds a **shortest-path tree**
✅ Can be stopped early if only the shortest path to a destination is needed

## 🌍 **Applications**
* **GPS navigation** (finding shortest driving routes)
* **Network routing** (e.g., OSPF protocol)
* **Game AI** (pathfinding)
* **Flight booking systems** (cheapest flights)

## ⚠️ **Limitations**
* **Does NOT work with negative edge weights** – use **Bellman-Ford** instead.
* For graphs with **very dense edges**, **Floyd-Warshall** or even **Bellman-Ford** may be considered.

### Key Terms in Graph Theory

A **graph** consists of two primary components:
1. **Nodes (Vertices):** The fundamental units of the graph, similar to tree nodes.
2. **Edges:** Connections between nodes.

### Types of Graphs Based on Edges
1. **Directed Graph (Digraph):**  
   Edges have a direction, indicating a one-way connection between nodes.
2. **Undirected Graph:**  
   Edges have no direction, indicating a two-way connection.

   > **Note:** An undirected graph can be represented as a directed graph by treating each undirected edge as two directed edges.

3. **Weighted Graph:**  
   Each edge is assigned a weight or cost, representing a quantitative value like distance or time.
4. **Unweighted Graph:**  
   Edges have no weight, and all connections are treated equally.

### Special Types of Graphs
1. **Complete Graph:**  
   Every node is directly connected to every other node.
   - Number of edges in an **undirected complete graph:** nC2 = n(n-1)/2
   - Number of edges in a **directed complete graph:** nC2 * 2 = n(n-1)

2. **Bipartite Graph:**  
   A graph that can be colored using two colors such that no two adjacent nodes have the same color.
   - A graph containing an odd-length cycle is not bipartite.


### Graph Terminology
1. **Adjacent Nodes:**  
   Two nodes are adjacent if they are directly connected by an edge.
2. **Reachable Nodes:**  
   A node `u` is reachable from `v` if there exists a path (a sequence of edges) connecting them.
3. **Connected Components:**  
   In a **disconnected graph**, the largest sets of nodes where every pair of nodes is reachable form **connected components**.
4. **Self-Loop:**  
   An edge that connects a node to itself.
    - A self-loop is also a cycle.
5. **Parallel Edges:**  
   Multiple edges connecting the same pair of nodes.
6. **Cycle:**  
   A path that starts and ends at the same node without repeating edges.
7. **Simple Path:**  
   A path with no repeated edges.

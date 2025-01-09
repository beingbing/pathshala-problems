# Graph Representation
Graphs can be represented in two common ways:

## 1. Adjacency List
Efficient for sparse graphs, where not all nodes are connected.

### Structure:
Each node stores a list of its adjacent nodes (or a list of pair of node and weight if edges are weighted). Thus, the degree of each node can be defined as the size of its adjacency list.

### Complexity:
- **Space Complexity:** It depends on the total number of nodes (`v`) and edges (`e`) and can be defined as the sum of size of adjacency-lists of all the nodes, which in turn is equal to the degree of the graph. hence O(v + 2e) which gets normalized into O(v + e)
- **Time Complexity:** Traversing all adjacency lists involves visiting each node and its edges, hence, time complexity will be O(v + e)

### Note:
In a complete graph there is an edge between every two nodes. Hence both time and space complexity will be O(v^2) -
```
 => e = vC2 = v*(v-1)/2 
 => e = v^2
```

## 2. Adjacency Matrix
Efficient for dense graphs, where most nodes are connected.

### Structure:
- A `v × v` matrix where `mat[i][j] = 1` if there's an edge between `i` and `j`, otherwise `0`.
- In a **weighted graph**, `mat[i][j]` stores the weight of the edge, or `0` if no edge exists.

### Complexity:
- **Space Complexity:** O(v^2)
- **Time Complexity for Traversal:** O(v^2)

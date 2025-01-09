# Rooted vs. Unrooted Trees

### Rooted Trees
- One node is explicitly chosen as the root.
- From the root, all other nodes are organized hierarchically, and concepts like parent, child, and depth become well-defined.

### Unrooted Trees
-  no specific node is designated as the root. Any node can be treated as the root temporarily for traversal purposes.
- It is simply a connected, acyclic graph.

## Tree Traversal
Traversal methods like Depth-First Search (DFS) or Breadth-First Search (BFS) are commonly used to explore the entire structure. To traverse an unrooted tree, you can pick any node as the temporary root, but tree properties dependent on root won't remain fixed.

### Properties
- **Height:** The height of a tree is defined with respect to the root. If the root changes, the height may change as well.
- **Diameter:** The diameter of a tree is the longest path between any two nodes. It is independent of the choice of the root since it considers all nodes in the tree.

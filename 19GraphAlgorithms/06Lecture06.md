### BFS Tree
A **BFS Tree** is a tree derived from a graph such that its **level-order traversal** matches the **BFS traversal** of the graph. In this tree:
1. **Edges in the BFS Tree:** Only the edges responsible for adding nodes to the BFS queue are part of the tree.
2. **Node Levels:** Each node is placed at the lowest possible level (shortest distance from the root node).
3. The **level** of a node in the BFS tree represents its **shortest path (in terms of edges)** from the root node in the original graph.

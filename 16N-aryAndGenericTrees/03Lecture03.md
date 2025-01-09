# Generic (N-ary) Tree Traversal
There are two types of traversal -
- Depth-first traversal
- Breadth-first traversal

## Depth-first traversal (DFS) of an N-ary tree
If we take inspiration from DFS of a graph, then we would consider introducing a list of visited nodes to keep track of nodes which are already seen to not get stuck in a loop. But as N-ary tree has a property of not having any loop, hence tracking visited nodes via a list would be an overdo. Instead, we only need to keep track of parent. We traverse all adjacent nodes but the parent.

### Key Observations
Tree details provided differ, according to the rootedness property -
- If tree is rooted, root node will be provided. There are two ways to traverse it -
  - Traversal using nodes
  - Traversal by generating adjacency-list.
- If tree is unrooted, adjacency list will be provided.

### Note
Traversing an unrooted tree can be treated as a sub-portion of traversing a rooted tree using its adjacency list.

### DFS Traversal using adjacency-list
- Decide on a root node (if not provided) to start the traversal.
- A leaf node has only one neighbor in its adjacency list (except for the root, which might also have one neighbor).
- All non-leaf nodes will have atleast two neighbors.
- Optionally, to simplify traversal, a dummy parent node can be assigned when the root has only one neighbor.

### DFS Traversal using nodes
- implement it using both recursion and iteration

# Heap and Its Operations
A **heap** is a specialized tree-based data structure that satisfies the heap property:
- **Min-Heap**: Every parent node is less than or equal to its children. The smallest value is always at the root.
- **Max-Heap**: Every parent node is greater than or equal to its children. The largest value is always at the root.

To efficiently support operations like `insert`, `delete`, and `getMax` (or `getMin`), a heap is typically implemented as a **complete binary tree** using an array.

## Representing a Heap with an Array
In an array-based heap:
1. The root node is at index `1` (index `0` is ignored).
2. For a node at index `i`:
    - Left child is at index `2 * i`.
    - Right child is at index `2 * i + 1`.
3. For a node at index `j`, its parent is at index `floor(j / 2)`.

This arrangement ensures that the tree remains a **complete binary tree**:
- Nodes are filled level by level, from left to right.
- There is at most one non-leaf node with a single left child, located at index `n / 2` (where `n` is the total number of nodes).

## Operations in a Heap
### 1. **Insert Operation**
To insert an element `k`:
- Add `k` at the next available index in the array.
- Perform "heapify-up" (also called "bubble-up") to restore the heap property.

### 2. **Delete Operation**
To delete an element at position `pos`:
- Swap the element at `pos` with the last element.
- Remove the last element.
- Perform "heapify-down" to restore the heap property.

### 3. **Get Maximum (or Minimum)**
In a max-heap, the maximum value is at the root (index `1`). Similarly, in a min-heap, the minimum value is at the root.

### 4. Converting an Array to a Heap
Start from the last non-leaf node (index `n / 2`) and perform "heapify-down" for each node in reverse level order.

### Time complexity:
- `insert`: O(log n)
- `delete`: O(log n)
- `getMax`: O(1)
- `buildHeap`: O(n)

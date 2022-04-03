~~ what is heap ~~

create a DS to support following operations -
- insert(k): insert an integer k in your DS
- delete(pos): delete at a given positions
- getMax(): get maximum of those elements

to accomplish above three operations efficiently, we need a hierarchical DS, specifically a tree, we can use
BT to keep things simple. But here, tree implementation will be a little different from what we have done
till now, instead of pointers and nodes we will use an array.

an array can be perceived as a binary tree.
placing the root at index 1 (0th index will be ignored) then with every root i has it's left child at index
2*i and right child at index 2*i+1 in array.
and for each node j it's parent will be floor(j/2).

The above arrangement will always result in a complete binary tree. Because, every new level will start from
left-most node and will be filled-in progressively from left to right. That's also because of the contiguous
nature of indices of array, as every new element will be placed at next index linearly.

Note: there can only possibly be one non-leaf node with 1 child and that child will always be a left child.
Note: that non-leaf node will be the last non-leaf node in level order traversal.
Note: you can always get position of that non-leaf node from last node, as it will always be the case that
the particular non-leaf node is parent of last node. so if there are n nodes that last non-leaf node will
be at n/2. so nodes from 1 till n/2 will all be non-leaf nodes and nodes from n/2+1 till n will all be leaf
nodes.

Heap => an array perceived as a complete binary tree. 

heap can be of two types -
- minHeap   - maxHeap

minHeap -
every parent <= both its direct children
smallest value will always be the root.

so, minHeap is a good DS to determine current min, but if we extend and looks for kth smallest we need to keep
deleting root k times and then do heapification so that it stays a minHeap.

maxHeap -
every parent >= both its direct children
maximum value will always be the root.

Q. given an array convert it into a min/max heap ?

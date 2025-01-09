# Introduction to N-ary Trees and its Representation

A **tree** is a connected, acyclic graph. For a tree with **n nodes**, there will always be exactly **n-1 edges**.

## Representation of Generic N-ary Trees
In a generic n-ary tree, a node can have any number of children, making it impractical to define a tree node with a fixed number of pointers. Unlike a binary tree, where each node has `left` and `right` pointers for its two children, an n-ary tree node must accommodate an arbitrary number of children at runtime.

To handle this, we use a structure where each node maintains a list (or array) of pointers to its children. However, for efficient representation of the tree, especially when dealing with edge inputs, we rely on an **Adjacency List**.

### Why Use an Adjacency List?
An adjacency list efficiently represents trees:
- Instead of using a fixed-size matrix (which would waste space for sparse trees), we use a vector of vectors.
- For a tree with **n nodes** and **E edges** (where **E can go up to n-1**) we will have atmost 2n-2 entries, which is nowhere near the n^2 space we preserve in case of a matrix.

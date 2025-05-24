# Disjoint set union
## Problem Statement
We have n person from 1 to n partitioned in different rooms. Implement following functions:
- `find(x)`: given person id, return room number in which that person is present.
- `union(x, y)`: merge rooms in which person x and y are present into a single room.

## Example:
Input:
```
[[1,3],[5],[2],[4,7,9],[8,10,6]]
find(8) = 5
union(3,0) = [[1,3,4,7,9],[5],[2],[8,10,6]]
union(8,6) = no change
``` 

## Solution
Consider each person to be a node of a graph, and persons which belong in the same room are connected components of that graph.
So, making union of persons present in the same room will lead to a cycle but doing so with persons of different room will not. So, the process of finding the cycle can be rethought using union-find algorithm.

### Approach 1: Brute-force
If we maintain an array of sets, where index will be person id and value will be the set in which that person is present. Then, find() will become an O(1) operation and union() will have TC of O(n).

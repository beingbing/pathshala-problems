# Topological sort alternative approach
DFS can also be written as, first print i, followed by all those which directly depends on i.

```
DFS(node)
  isVis[node] = true;
  call for unvisited adjacent nodes
  stk.push(node)
```
call it from a driver function.
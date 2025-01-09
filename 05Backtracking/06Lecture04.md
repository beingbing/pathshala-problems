# Paths - 1
## Problem
Given a square maze represented by a 2D matrix, where:
- `0` represents a safe cell.
- `1` represents a poisonous cell.
Print all valid paths for a rat to reach the destination at (n-1, n-1) starting from (0, 0), with movement restricted to only right or down.

## Solution
```java
import java.util.ArrayList;
import java.util.List;

public class RatInMaze {

    public static List<String> findPaths(int[][] maze) {
        List<List<int[]>> paths = new ArrayList<>();
        List<int[]> path = new ArrayList<>();
        int n = maze.length;
        backtrack(maze, n - 1, 0, 0, path, paths);
        return paths;
    }

    private static void backtrack(int[][] maze, int boundary, int row, int col, List<int[]> path, List<List<int[]>> paths) {
        if (maze[row][col] == 1) return;

        if (row == boundary && col == boundary) {
            path.add(new int[]{row, col});
            paths.add(new ArrayList<>(path));
            path.removeLast();
            return;
        }

        path.add(new int[]{row, col});
        if (isSafe(col, boundary)) backtrack(maze, boundary, row, col + 1, path, paths);
        if (isSafe(row, boundary)) backtrack(maze, boundary, row + 1, col, path, paths);
        path.removeLast();
    }

    private static boolean isSafe(int val, int boundary) {
        return val + 1 <= boundary; 
    }

    public static void main(String[] args) {
        int[][] maze = {
                {0, 0, 1},
                {0, 0, 0},
                {1, 0, 0}
        };
        List<List<int[]>> paths = findPaths(maze);
        System.out.println(paths);
    }
}
```

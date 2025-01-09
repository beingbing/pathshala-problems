# Paths - 2
## Problem
You are given an m * n grid where each cell has:
- 1 representing the starting square (exactly one in the grid).
- 2 representing the ending square (exactly one in the grid).
- 0 representing walkable empty squares.
- -1 representing obstacles (non-walkable squares). 
Return the number of unique paths from the starting square to the ending square, moving only in four directions (up, down, left, right).

Constraints:
- 1 <= m, n <= 20
- 1 <= m * n <= 20
- Each grid contains exactly one starting square and one ending square.

## Solution
We need to find the number of unique paths from a starting cell to an ending cell in an `m * n` grid

### Key Insights
1. **Backtracking and Exhaustive Search**:
    - Since the grid is relatively small (maximum size 20x20), an exhaustive backtracking search to explore all possible paths is feasible.
2. **Tracking Visited Cells**:
    - Use backtracking to move to unvisited cells.
    - Track cells visited on the current path to prevent revisiting cells, except the starting and ending cells.
3. **Recursive Exploration**:
    - For each cell, recursively explore the four possible directions.
4. **Base Case of Recursive Function**:
    - The path is complete if we reach the ending cell (`2`)

### Approach:
1. **Locate Starting Point and Count Walkable Cells**:
    - Iterate through the grid to find the starting cell's position.
2. **Recursive Backtracking**:
    - From the starting cell, explore all four directions (up, down, left, right) if the next cell is within grid bounds and walkable.
    - Decrement the count of remaining cells when visiting a cell, and increment when backtracking

### Code
```java
import java.util.ArrayList;
import java.util.List;

public class Solution {
    private boolean[][] isVisited;

    private boolean isSafe(int[][] grid, int i, int j) {
        if (i < 0 || i >= grid.length) return false;
        if (j < 0 || j >= grid[0].length) return false;
        if (grid[i][j] == -1) return false;
        return true;
    }

    private int countPaths(int[][] grid, int i, int j) {
        if (grid[i][j] == 2) return 1;

        isVisited[i][j] = true;
        int sum = 0;

        if (isSafe(grid, i, j + 1) && !isVisited[i][j + 1]) sum += countPaths(grid, i, j + 1);
        if (isSafe(grid, i, j - 1) && !isVisited[i][j - 1]) sum += countPaths(grid, i, j - 1);
        if (isSafe(grid, i + 1, j) && !isVisited[i + 1][j]) sum += countPaths(grid, i + 1, j);
        if (isSafe(grid, i - 1, j) && !isVisited[i - 1][j]) sum += countPaths(grid, i - 1, j);

        isVisited[i][j] = false;
        return sum;
    }

    public int uniquePathsIII(int[][] grid) {
        int startX = 0, startY = 0;
        int n = grid.length;
        int m = grid[0].length;
        isVisited = new boolean[n][m];

        // Locate the starting cell
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                    break;
                }

        // Start counting paths from the starting cell
        return countPaths(grid, startX, startY);
    }

    public static void main(String[] args) {
        int[][] grid = {{1, 0, 0, 0}, {0, 0, 2, -1}};
        Solution solution = new Solution();
        System.out.println(solution.uniquePathsIII(grid)); // Output should be 2
    }
}
```

### Complexity
- **Time Complexity**: `O(4^{m * n})`, With four possible moves at each cell, the backtracking explores a large number of paths. Pruning paths by marking cells as visited helps reduce this.
- **Space Complexity**: `O(m * n)`, The recursion stack depth reaches in the worst case.

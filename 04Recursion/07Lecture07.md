# Distinct Paths in an m x n Grid
**Problem Statement**:  
A rat starts at the top-left cell of an `m * n` grid `(0, 0)` and must reach the bottom-right cell `(m-1, n-1)`. The rat can only move **right** or **down**. We need to determine the number of distinct paths from the starting point to the destination.

## Recursive Solution Overview
To approach this problem recursively, consider how the rat moves:
- From each cell, the rat has two possible directions: right or down.
- The number of paths to a cell `(i, j)` is the sum of paths to the cells directly **above** `(i-1, j)` and **left** `(i, j-1)`.

The recurrence relation can be defined as:
```
pathsCount(i, j) = pathsCount(i + 1, j) + pathsCount(i, j + 1)
```

### Termination Condition
1. If the rat is at the **rightmost column** or **bottommost row**, it can only move in one direction.
2. If the rat reaches cell `(m-1, n-1)`, we return 1 as this is the final destination.

### Code
```java
import java.util.Scanner;

public class DistinctPaths {

    static int m, n;

    // Recursive function to count paths
    public static int countPaths(int i, int j) {
        if (i == m - 1 || j == n - 1) return 1;
        return countPaths(i + 1, j) + countPaths(i, j + 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        m = scanner.nextInt();
        n = scanner.nextInt();
        scanner.close();

        int result = countPaths(0, 0);
        System.out.println("Total distinct paths: " + result);
    }
}
```

#### Complexity Analysis
- **Time Complexity**: `O(2^{m+n})` due to the binary tree structure created by two recursive calls per function call, with a depth of `m+n`.
- **Space Complexity**: `O(m + n)` for the maximum recursive stack height.

#### Note
This approach demonstrates recursion, but it’s not the most efficient due to overlapping subproblems. A more optimal solution would use -
- **dynamic programming** to avoid redundant calculations.
- binomial (combinatorial) expression to directly calculate the result.

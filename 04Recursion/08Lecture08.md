# Distinct Paths in an m x n Grid – Alternative Implementations

**Problem Statement**  
A rat starts at the top-left cell of an `m * n` grid, `(0, 0)`, and must reach the bottom-right cell `(m-1, n-1)`. The rat can move **right** or **down** only. We need to calculate the total number of distinct paths it can take to reach its destination.

## Solution Approaches
### 1. Recursive Function with Void Return (Top-Down)
This approach uses a recursive function to explore every possible path. It utilizes a global counter to keep track of distinct paths.

**Steps**:
1. **Base Case**: When the rat reaches either the bottom row or the rightmost column, increment the global path counter, `cnt`, as there’s only one path left (either right or down).
2. **Recursive Calls**: Move **down** by calling `countPaths2(i+1, j)` and move **right** by calling `countPaths2(i, j+1)`.

#### Code
```java
import java.util.Scanner;

public class DistinctPathsTopDown {
    static int m, n;
    static int cnt = 0;

    // Recursive function to count paths
    public static void countPaths2(int i, int j) {
        if (i == m - 1 || j == n - 1) {
            cnt++;
            return;
        }
        countPaths2(i + 1, j);  // Move down
        countPaths2(i, j + 1);  // Move right
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        m = scanner.nextInt();
        n = scanner.nextInt();
        scanner.close();

        countPaths2(0, 0);
        System.out.println("Total distinct paths: " + cnt);
    }
}
```

### 2. Bottom-to-Top Recursion with Return Type
This alternative approach calculates the paths from the **bottom-right cell to the top-left cell** recursively. Starting from the destination cell, it traces back paths to the starting cell. Instead of using a global variable, the function returns the path count directly.

**Steps**:
1. **Base Case**: If either `i == 0` or `j == 0`, return `1` because there’s only one possible path (either all the way left or all the way up).
2. **Recursive Calls**: Move **up** by calling `countPaths3(i - 1, j)` and **left** by calling `countPaths3(i, j - 1)`.

#### Code
```java
import java.util.Scanner;

public class DistinctPathsBottomUp {

    // Recursive function to count paths using bottom-to-top approach
    public static int countPaths3(int i, int j) {
        if (i == 0 || j == 0) return 1;  // Base case
        return countPaths3(i - 1, j) + countPaths3(i, j - 1);  // Move up and left
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        scanner.close();

        int result = countPaths3(m - 1, n - 1);
        System.out.println("Total distinct paths: " + result);
    }
}
```

# Applications of Catalan Numbers

## Problem 1: Paths in an `n * n` Grid
**Objective**: Given an `n * n` grid, find the total number of possible paths from the top-left corner `(0,0)` to the bottom-right corner `(n-1, n-1)`, when movements are restricted to right (R) and down (D) directions.

### Solution:
1. **Path Construction**:
    - Each path must contain exactly `n-1` rights (R) and `n-1` downs (D) to reach `(n-1, n-1)`.
    - The total length of each path is `2n - 2`.
2. **Counting Distinct Paths**:
    - We need to create unique arrangements of `R` and `D` steps in a sequence of length `2n-2`.
    - Using combinations, we can choose any `n-1` of these `2n-2` positions to assign to `R` (the remaining will be `D`), resulting in: `(2n - 2)C(n - 1)`.

#### Generalized Formula
For an `m * n` grid, where we move `m-1` steps down and `n-1` steps right:
```
Paths = (m + n - 2)C(m - 1) or (m + n - 2)C(n - 1)
```

#### Code
```java
public class GridPaths {
    // Method to calculate nCr (combinations)
    public static int nCr(int n, int r) {
        int res = 1;
        r = Math.min(r, n - r);  // Use the smallest of r and n-r
        for (int i = 0; i < r; i++) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }

    public static int gridPaths(int m, int n) {
        return nCr(m + n - 2, m - 1);  // or nCr(m + n - 2, n - 1)
    }

    public static void main(String[] args) {
        int m = 4, n = 4;
        System.out.println("Total paths in a " + m + "x" + n + " grid: " + gridPaths(m, n));
    }
}
```

## Problem 2: Paths Restricted by the Diagonal in an `n * n` Grid
**Objective**: In an `n * n` grid, count the number of paths from `(0,0)` to `(n-1, n-1)` such that the path never crosses the main diagonal (i.e., paths are restricted to cells where the count of down moves is always at least the count of right moves).

### Solution:
1. **Path Constraint**:
    - For any valid path, the count of down moves (D) must always be greater than or equal to the count of right moves (R) at every point.
    - This condition mirrors the balanced parentheses problem where open brackets must not be fewer than close brackets at any point.
2. **Catalan Number Solution**:
    - The problem reduces to counting combinations equivalent to balanced parentheses with `n-1` pairs, following the recurrence:
```
      f(n-1) = {i -> 0, n-2} ∑  (f(i) * f(n-2 - i))
      where f(0) = 1 and f(1) = 1.
```

### Java Code
```java
public class DiagonalRestrictedPaths {
    public static int catalan(int n) {
        int[] dp = new int[n + 1];
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }

    public static void main(String[] args) {
        int n = 4; // For n x n grid
        System.out.println("Paths restricted by diagonal in " + n + "x" + n + " grid: " + catalan(n - 1));
    }
}
```

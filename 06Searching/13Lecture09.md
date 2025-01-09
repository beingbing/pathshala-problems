# square root
## Problem
given a number non-negative number n find it's square-root, or floor of square root if it's not a perfect square.

### Solution
#### Key Insights
1. **Binary Search Approach**:
    - Use two pointers, `low` and `high`, to represent the range `[0, n]`.
    - Calculate `mid` as the average of `low` and `high`, and then check if `mid * mid` is equal to `n`, less than `n`, or greater than `n`.
    - Adjust `low` or `high` based on whether `mid * mid` is less than or greater than `n`, respectively.
2. **End Condition**:
    - When `low` exceeds `high`, the algorithm terminates, and the answer is the largest `mid` where `mid * mid` was less than or equal to `n`.

#### Code
```java
class Solution {
    public int mySqrt(int n) {
        if (n < 2) return n; // For 0 and 1, the square root is the number itself.

        int low = 0, high = n;
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2; // Prevent overflow

            // Use long to prevent overflow when calculating mid * mid
            long square = (long) mid * mid;

            if (square == n) return mid; // Perfect square case
            else if (square < n) {
                result = mid; // Store this mid as a potential answer
                low = mid + 1; // Move to the right half
            } else high = mid - 1; // Move to the left half
        }

        return result; // Return the floor of the square root
    }
}
```

#### Complexity
- **Time Complexity**: `O(log n)`, as we perform a binary search.
- **Space Complexity**: `(O(1)`, only a few extra variables.

### Note
this technique has its own name, binary search on answer. here, you first find the domain then implement BS on it.

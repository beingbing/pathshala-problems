# Divide and Conquer
**Concept**:
   Divide and Conquer is a problem-solving strategy that involves three main steps:
   - **Divide**: Split the problem into smaller, manageable subproblems.
   - **Conquer**: Solve each subproblem individually, often recursively.
   - **Combine**: Merge the solutions of subproblems to solve the original problem.

## Problem
Given an integer array `a`, find the maximum element using the Divide and Conquer approach.

### Solution
#### Recursive Relation
To find the maximum in `a`, divide the array into two halves until reaching individual elements. Then, compare each element from divided parts to find the maximum.
- **Recursive Relation**: `T(n) = 2T(n/2) + O(1)`
- Here, `2T(n/2)` represents the two recursive calls for the left and right halves, and `O(1)` is the comparison step.

#### Termination Condition
When a single element is left, return that element as it is the maximum in that subarray.

#### Code
```java
import java.util.Arrays;

public class Solution {
    public int findMax(int[] arr, int start, int end) {
        // Termination condition
        if (start == end) return arr[start];
        
        // Divide step: calculate mid-point
        int mid = start + (end - start) / 2;
        
        // Recursive calls for left and right halves
        int leftMax = findMax(arr, start, mid);
        int rightMax = findMax(arr, mid + 1, end);
        
        // Conquer step: return the maximum of leftMax and rightMax
        return Math.max(leftMax, rightMax);
    }

    public static void main(String[] args) {
        int[] arr = {7, 1, 4, 3, 2, 6, 5};
        Solution solution = new Solution();
        int max = solution.findMax(arr, 0, arr.length - 1);
        System.out.println("Maximum element: " + max);
    }
}
```

### Complexity Analysis
In a recursion tree, no of leaves = n, no of nodes above it n/2, so - 
```
n + n/2 + n/4 + .... = 2n
TC = 2n * 1 // as every step is doing O(1) work
```
- **Time Complexity**: `O(n)`, since each element is compared once.
- **Space Complexity**: `O(log n)`, due to recursion depth equal to the height of the recursion tree.

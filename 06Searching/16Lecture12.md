# k-th Smallest Element in a Matrix
## Problem
Given an `n*n` matrix where duplicate elements can be present and only rows are sorted. Find the k-th smallest element in the matrix.

Example:
For `k = 6` and matrix:
```
1  3  5
1  2  9
4  5  6
```
If we sort the elements, we get: `1, 1, 2, 3, 4, 5, 5, 6, 9`, so the 6th smallest element is `5`.

### Solution
#### Approach 1: Temporary Array and Sorting
1. **Create a temporary array** of size n*n for all elements in the matrix.
2. **Sort the array** and retrieve the element at index `k - 1`.

**Complexity**:
- **Time**: `O(n^2 + (n^2)8 log(n^2)) = O((n^2) log(n))`
- **Space**: `O(n^2)`

While this approach is straightforward, it requires extra space and has a high time complexity.

#### Approach 2: Binary Search on the Answer (Optimized for Row-Sorted Matrices)
We can use **Binary Search on the answer range** and find the count of elements less than or equal to a given candidate element `mid`, which can help determine if `mid` is too low or high for the k-th smallest.

##### Steps
1. **Define bounds**:
    - Set `low` as the smallest element in the matrix, which is the overall minimum element of the first column.
    - Set `high` as the largest element, overall maximum element of the last column

2. **Counting Elements ≤ mid Efficiently**:
    - Use `countLessEqual`, a helper function to count elements ≤ `mid` across rows by leveraging the row-wise sorted property.
    - For each row, perform a binary search to count elements ≤ `mid`, contributing to an overall count.
    - alternatively, we cal look for upper_bound for every given `mid` as well.
    - upper_bound is the element strictly greater than the given element.

3. **Binary Search on Answer**:
    - Use binary search to find the smallest element with at least `k` elements ≤ itself:
        - Set `mid = (low + high) / 2`.
        - Get `count` of elements ≤ `mid` using `countLessEqual`.
        - If `count < k`, increase `low` (focus on larger elements); otherwise, reduce `high`.

    - When the loop completes, `low` will point to the k-th smallest element.

#### Code
```java
public class KthSmallestInMatrix {
    
    // Helper function: Counts numbers <= target using binary search in each row
    private int countLessEqual(int[][] matrix, int target) {
        int count = 0;
        int n = matrix.length;

        for (int i = 0; i < n; i++) {
            int low = 0, high = n - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (matrix[i][mid] <= target) low = mid + 1; // Move right
                else high = mid - 1; // Move left
            }
            count += low; // Count of elements <= target in this row
        }

        return count;
    }
    
    private int findLowest(int[][] matrix) {
        int min = Integer.MAX_VALUE;
        int rows = matrix.length;
        
        for (int i = 0; i < rows; i++)
            min = Math.min(matrix[i][0], min);
        
        return min;
    }
    
    private int findLargest(int[][] matrix) {
        int max = Integer.MIN_VALUE;
        int rows = matrix.length;
        
        for (int i = 0; i < rows; i++)
            max = Math.max(matrix[i][rows - 1], max);
        
        return max;
    }

    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        int low = findLowest(matrix); // Minimum element in matrix
        int high = findLargest(matrix); // Maximum element in matrix

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = countLessEqual(matrix, mid);

            if (count < k) low = mid + 1; // Increase lower bound
            else high = mid; // Decrease upper bound
        }

        return low; // Low points to the k-th smallest element
    }

    public static void main(String[] args) {
        KthSmallestInMatrix finder = new KthSmallestInMatrix();
        int[][] matrix = {
            {1, 3, 5},
            {1, 2, 9},
            {4, 5, 6}
        };
        int k = 6;
        System.out.println("The " + k + "-th smallest element is " + finder.kthSmallest(matrix, k));
    }
}
```

### Complexity Analysis
- **Time Complexity**: `O(n log(n) * log(max - min))`
    - Binary search on the range `[min, max]` contributes `O(log(max - min))`.
    - For each midpoint, `countLessEqual` takes `O(n log n)` due to binary search in each row.

- **Space Complexity**: `O(1)`
    - No additional space is used beyond input and variables.

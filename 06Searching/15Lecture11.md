# k-th Smallest Element in an Array
Optimized by finding Monotonicity

## Problem
Given an unsorted array with possible duplicates and an integer `k`, find the k-th smallest element without modifying the array or using extra space.

### Solution
In this approach, we further optimize the solution from `O(n^2)` by leveraging a monotonic property and binary search.

#### Insight into Monotonicity
In the previous solution, for every element, we checked the count of values that were less than or equal to it. However, if we find that a particular count does not meet our `k` requirement, we can use the monotonic nature of the counts to limit our search space:
1. **Monotonic Count Property**:
    - If an element `x` has fewer than `k` elements less than or equal to it, all elements smaller than `x` will also have fewer than `k` such elements. So, we can discard elements less than `x`.
    - Conversely, if `x` has `k` or more elements less than or equal to it, we may have found a candidate, or else we move to smaller values to continue the search.

2. **Binary Search with Count Function**:
    - Use binary search to narrow down on the candidate value by setting initial bounds as the value of minimum and maximum elements of the array.
    - Use a helper function, `countNums(x)`, to count elements less than or equal to `x`.
    - Adjust the binary search bounds based on the count results:
        - If `countNums(mid) < k`, move to the right (higher values).
        - Otherwise, check if `countNums(mid - 1) < k` to confirm `mid` is the k-th smallest. If not, move to the left.

#### Code
```java
public class KthSmallestFinderOptimized {

    // Helper function to count elements <= x
    private int countNums(int[] a, int x) {
        int count = 0;
        for (int num : a) if (num <= x) count++;
        return count;
    }

    public int kthSmallest(int[] a, int k) {
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;

        // Determine the min and max in the array
        for (int num : a) {
            min = Math.min(min, num);
            max = Math.max(max, num);
        }

        int low = min, high = max;

        // Binary search between min and max
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = countNums(a, mid);

            if (count < k) low = mid + 1; // Move to higher values
            else {
                // Check if this is the k-th smallest element
                int countLower = countNums(a, mid - 1);
                if (countLower < k) return mid; // Found k-th smallest
                else high = mid - 1; // Move to lower values
            }
        }

        // If no element meets criteria (shouldn't happen with valid k)
        throw new IllegalArgumentException("Invalid input: k is out of range");
    }

    public static void main(String[] args) {
        KthSmallestFinderOptimized finder = new KthSmallestFinderOptimized();
        int[] arr = {40, 10, 10, 30, 40, 20, 50, 70, 50};
        int k = 6;
        System.out.println("The " + k + "-th smallest element is " + finder.kthSmallest(arr, k));
    }
}
```

### Complexity Analysis
- **Time**: `O(n log(max - min))`: For each binary search step, `countNums` is `O(n)`, and binary search takes `O(log(max - min))`.
- **Space**: `O(1)`, meeting the no extra space constraint. 

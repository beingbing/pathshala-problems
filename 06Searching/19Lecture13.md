# maximize k
## Problem
Given:
- An array `v` of positive integers (unsorted).
- A non-negative integer `x`.
  The task is to find the maximum possible size `k` of a subarray such that no subarray of length `k` has a sum greater than `x`. We want to maximize `k` while maintaining this condition.

### Solution
1. **Binary Search on Answer**:
    - To find the maximum possible length `k`, we perform binary search on possible values of `k`, from `1` to `n` (where `n` is the array length).
    - For each midpoint `m`, we check if a subarray of size `m` can satisfy the condition where the sum of elements in every subarray of that size is ≤ `x`.
2. **Monotonicity**:
    - The problem exhibits a monotonic property: if a subarray of length `k` fails the condition (sum > `x`), then any longer subarray will also fail.
    - Conversely, if a subarray of length `k` satisfies the condition (sum ≤ `x`), then any shorter subarray will also satisfy it.
3. **Checking the Condition for Each `k`**:
    - For a given `m` (candidate size for `k`), we calculate the sum of each subarray of length `m` using a sliding window approach.
    - This sliding window sum calculation takes O(n) time.
4. **Binary Search Implementation**:
    - We set `low` to 1 and `high` to `n`.
    - For each midpoint `m`, we call `isPossible(m, x)`, which checks if every subarray of length `m` has a sum ≤ `x`.
    - If `isPossible(m, x)` is true, we increase `low` to search for a larger `k`. Otherwise, we decrease `high` to search for a smaller `k`.

### Code
```java
public class MaxSubarrayLength {
    public int findMaxK(int[] nums, int x) {
        int n = nums.length;
        int left = 1, right = n;
        int maxK = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Check if subarrays of size mid are valid
            if (canHaveSizeK(nums, mid, x)) {
                maxK = mid; // mid is valid, try for larger k
                left = mid + 1;
            } else {
                right = mid - 1; // mid is too large, try smaller k
            }
        }
        
        return maxK;
    }
    
    // Helper function to check if subarrays of size k have a sum <= x
    private boolean canHaveSizeK(int[] nums, int k, int x) {
        int n = nums.length;
        
        // Initial window sum of first 'k' elements
        int windowSum = 0;
        for (int i = 0; i < k; i++) windowSum += nums[i];
        
        // Check if the first window is valid
        if (windowSum > x) return false;
        
        // Slide the window across the array
        for (int i = k; i < n; i++) {
            windowSum += nums[i] - nums[i - k]; // update window sum
            
            // If any window sum exceeds x, return false
            if (windowSum > x) return false;
        }
        
        // All windows of size k have a sum <= x
        return true;
    }
}
```
```java
public class MaxSubarraySize {

    // Check if a subarray of size m exists such that its sum is <= x
    private static boolean isPossible(int[] arr, int m, int x) {
        int n = arr.length;
        if (m > n) return false;

        // Calculate initial window sum
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += arr[i];
        }

        // If initial window sum exceeds x, return false immediately
        if (sum > x) return false;

        // Slide the window and update the sum
        for (int i = m; i < n; i++) {
            sum += arr[i] - arr[i - m];  // Slide the window forward
            if (sum > x) return false;   // If any window exceeds x, return false
        }

        // If no window exceeded x, return true
        return true;
    }

    // Function to find the maximum subarray size k with sum <= x
    public static int maxSubarraySize(int[] arr, int x) {
        int low = 1;
        int high = arr.length;
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(arr, mid, x)) {
                result = mid; // Track the largest possible size
                low = mid + 1; // Try for a larger size
            } else {
                high = mid - 1; // Try for a smaller size
            }
        }

        return result;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        int x = 9;
        System.out.println("Maximum size of subarray with sum <= " + x + " is: " + maxSubarraySize(arr, x));
    }
}
```

### Complexity Analysis
- **Time Complexity**: `O(n log n)`
    - The binary search loop runs `O(log n)` iterations.
    - Each call to `isPossible` takes `O(n)` time due to the sliding window sum check.
- **Space Complexity**: `O(1)`
    - No additional data structures are used beyond constant space.

#### Note
For applying binary search on answer -
- come up with a function which is monotonic in nature
- come up with the range of answers from min to max

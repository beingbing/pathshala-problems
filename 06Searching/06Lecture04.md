# Searching in a Sorted Rotated Array
## Problem
Given a sorted, rotated array with distinct elements, find the index of a target element.

### Solution
In a sorted array that has been rotated at some pivot point, finding a target element efficiently requires either locating the pivot and applying binary search on the appropriate subarray or using a rotation-aware binary search approach. This guide explores both methods.

#### Approach 1: Pivot Finding + Binary Search on Segments
1. **Identify the Pivot**: The **pivot** in a rotated array is the index where the first sorted segment ends, and the second sorted segment begins. This is the maximum element in the array, which is also greater than its adjacent element. We can use binary search to locate this pivot efficiently.
2. **Binary Search on Segments**: Once the pivot is found, divide the array into two parts: from the start to the pivot, and from `pivot + 1` to the end. Determine in which segment the target lies, and apply binary search within that segment to find the target index.

##### Code
```java
public class Solution {
    public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0) return -1; // Edge case: empty array

        int pivotIdx = findPivot(nums);
        int n = nums.length;

        // If no rotation is found (pivotIdx is at end), search the entire array
        if (pivotIdx == n - 1) return binarySearch(nums, 0, n - 1, target);

        // Determine which side of the pivot to search
        if (nums[0] <= target && target <= nums[pivotIdx]) return binarySearch(nums, 0, pivotIdx, target);
        else return binarySearch(nums, pivotIdx + 1, n - 1, target);
    }

    // Finds the index of the pivot in a rotated sorted array
    // Pivot is the maximum element's index (e.g., the point of rotation)
    private int findPivot(int[] nums) {
        int n = nums.length;
        int low = 0, high = n - 1;

        // Edge case: the array is already sorted and not rotated
        if (nums[low] <= nums[high]) return n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // If the mid-element is greater than the next element, mid is the pivot
            if (mid < nums.length - 1 && nums[mid] > nums[mid + 1]) return mid;

            // Pivot lies on the side where the array is not sorted
            if (nums[low] <= nums[mid]) low = mid + 1;
            else high = mid;
        }
        return low - 1; // Returns pivot index
    }

    // Standard binary search method to find target within specified range
    private int binarySearch(int[] nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1; // Target not found
    }
}
```

#### Approach 2: Rotation-Aware Binary Search
This approach modifies binary search to account for rotation without explicitly finding the pivot.

**Key Observations**:
- The rotated array has two sorted halves.
- By evaluating the midpoint, we can determine if the target lies within a sorted half or the other mixed half.

**Logic**:
1. Check if the **left half** (from `left` to `mid`) is sorted. If so, determine if the target is within this range.
2. If the **right half** (from `mid` to `right`) is sorted, check if the target lies within this range.

##### Code
```java
public class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;  // Avoids overflow

            // Check if mid is the target
            if (nums[mid] == target) return mid;

            // Determine which part is sorted
            if (nums[left] <= nums[mid]) {
                // Left half is sorted
                if (nums[left] <= target && target < nums[mid]) right = mid - 1; // Target is in the left sorted half
                else left = mid + 1; // Target is in the right unsorted half
            } else {
                // Right half is sorted
                if (nums[mid] < target && target <= nums[right]) left = mid + 1; // Target is in the right sorted half
                else right = mid - 1; // Target is in the left unsorted half
            }
        }

        // Target not found
        return -1;
    }
}
```

#### Complexity Analysis
Both approaches operate within similar time and space complexities:
- **Time Complexity**: O(log n) for both approaches.
- **Space Complexity**: O(1), as no additional data structures are required.

### Food for Thought: Handling Duplicate Elements
When duplicates are allowed in the array, the above conditions to distinguish between sorted and unsorted halves can break down. Additional logic would be needed to manage cases where elements adjacent to `mid` are identical, often increasing complexity.

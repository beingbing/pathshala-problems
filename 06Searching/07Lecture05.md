# Peak Element
## Problem
given an unsorted array, find any peak element

### Solution
#### Insight
1. Binary Search Logic:
   - If we’re in a strictly increasing part of the array (i.e., nums[mid-1] < nums[mid]), it means there is a peak in the right half, as we are moving towards a higher element.
   - Conversely, if nums[mid] > nums[mid + 1], this means a peak must be on the left half (including mid), as we are at a "downward slope."

2. Binary Search Guarantees:
   - The array has at least one peak. If it’s a single-element array, that element itself is a peak.
   - We keep narrowing down the search space by moving to the half where a peak must exist.

#### Code
```java
public class Solution {
    public int findPeakElement(int[] nums) {
        int left = 0;
        int right = nums.length - 1;

        // Binary search to find the peak element
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid + 1]) left = mid + 1; // We are in an increasing part, peak must be on the right side
            else right = mid; // We are in a decreasing part, peak could be on the left side or at mid
        }

        // At the end of the binary search, left == right, pointing to a peak element
        return left;
    }
}
```

#### Intuition
In problems where the target element could lie in either half of a split based on a condition, binary search is ideal. Hence, we apply Binary Search when there is a condition separating the left and the right halves of the answer.

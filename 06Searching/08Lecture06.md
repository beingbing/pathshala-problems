# repeated element (SEEN IN MULTIPLE INTERVIEWS)
## Problem
Given a sorted array of `n` integers, where each integer is between `1` and `n-1`, all elements appear once except one, which appears twice. The task is to find the twice appearing element.

### Solution
#### Insight
1. Array Properties:
   - The array has n elements in the range `[1, n-1]`.
   - All elements are unique except for one element, which appears twice.
   - Since the array is sorted, the duplicate element will disrupt the index-to-value pattern that would otherwise hold.
2. Binary Search Approach:
   - In a perfectly sorted array with unique elements from 1 to n-1, we’d expect that each element a[i] matches the position pattern a[i] = i + 1.
   - When a duplicate is introduced, all subsequent elements in the array shift to the right, breaking this pattern.
3. Finding the Anomaly:
   - Using binary search, we can focus on the subarray where this pattern breaks:
   - If nums[mid] == mid + 1, it means all elements up to mid are in their correct positions, so the duplicate must be in the right half.
   - Otherwise, the duplicate is in the left half because the anomaly has started.

sample example -
n = 8

    1   2   3   4   5   5   6   7
    0   1   2   3   4   5   6   7

here we can see, both left and right sides of answer holds different conditions which can help us in deciding in which direction to move if we go with binary search.

left side of answer -> a[i] = i+1
right side of answer -> a[i] = i

so, our answer will be first element for which a[i] == i
or, our answer will be last element for which a[i] == i+1

code -

```java
public class Solution {
    public int findDuplicate(int[] nums) {
        int low = 0, high = nums.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if the disruption starts at mid
            if (nums[mid] == mid + 1) {
                if (nums[mid] == nums[mid + 1]) return nums[mid]; // Duplicate found
                else low = mid + 1; // Continue search in the right half
            } else {
                if (nums[mid] == nums[mid - 1]) return nums[mid]; // Duplicate found
                else high = mid - 1; // Continue search in the left half
            }
        }
        
        return -1; // Default case, ideally never reached with problem constraints
    }
}
```

or,

```java
public class Solution {
    public int findDuplicate(int[] nums) {
        int low = 0, high = nums.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If element matches mid + 1, search in the left half
            if (nums[mid] == mid + 1) {
                high = mid - 1;
            } else {
                // If a duplicate is found or nums[mid + 1] is different, return it
                if (nums[mid] == nums[mid + 1]) return nums[mid];
                else low = mid + 1; // Continue search in the right half
            }
        }

        return -1; // Default case, ideally never reached with problem constraints
    }
}
```

```java
    private static int findRepeating(int[] a) {
        int n = a.length;
        int left = 0, right = n - 1;

   // Binary search to find the duplicate element
        while (left < right) {
            int mid = left + (right - left) / 2;

           // The left half is correct, duplicate must be in the right half
            if (a[mid] == mid + 1) left = mid + 1;
            else right = mid;
           // The duplicate affects the right half, continue in the left half
        }

        return a[left];
    }
```

This shows that, binary search is not entirely dependent on elements being sorted, if you can establish a relation which can conclude in which direction to proceed then we can apply BS.


# single element in a sorted array
## Problem
You are given an unsorted array consisting of only integers where every element appears in pairs, except for one element which appears exactly once. Return the single element that appears only once.

### Solution

sample example -
n = 9
    4   4   1   1   3   7   7   6   6
    0   1   2   3   4   5   6   7   8

here we can see, both left and right sides of answer holds different conditions which can help us in deciding in which direction to move if we go with binary search.

left side of answer -> second element comes at odd index
right side of answer -> second element at even index

code -

if (a.size() == 1) return a[0];
low = 0, high = n-1
while (low <= high) {
    int mid = low + (high - low)/2
    if (mid == 0) {
        if (a[mid] != a[mid+1]) return a[mid];
        else low = mid + 1;
    } else if (mid == n-1) {
        if (a[mid-1] != a[mid]) return a[mid];
        else high = mid - 1;
    } else if (a[mid-1] != a[mid] && a[mid] != a[mid+1]) {
        return mid;
    } else {
        int firstOccurence, secondOccurence;
        if (a[m] == a[m+1]) {
            firstOccurence = m;
            secondOccurence = m+1;
        } else {
            firstOccurence = m-1;
            secondOccurence = m;
        }
        if (firstOccurence%2 == 0) low = mid + 1;
        else high = mid - 1;
    }
}

alternate approaches which will work for both sorted and unsorted array -
```java
public class Solution {
    public int singleNonDuplicate(int[] nums) {
        int low = 0, high = nums.length - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Adjust mid to be even for easier pairing
            if (mid % 2 == 1) mid--;

            // If the element at mid is part of a pair, move to the right half
            if (nums[mid] == nums[mid + 1]) low = mid + 2;
            else high = mid; // Unique element is in the left half or at mid
        }

        // Low will be at the unique element
        return nums[low];
    }
}
```

```java
public class Solution {
    public int singleNonDuplicate(int[] nums) {
        int left = 0;
        int right = nums.length - 1;

        // Binary search to find the single element
        while (left < right) {
            int mid = left + (right - left) / 2;

            // Check if mid is even or odd and compare accordingly
            if (mid % 2 == 0) {
                // If mid is even, check if the next element is the same
                if (nums[mid] == nums[mid + 1]) left = mid + 2; // Single element is in the right half
                else right = mid; // Single element is in the left half or at mid
            } else {
                // If mid is odd, check if the previous element is the same
                if (nums[mid] == nums[mid - 1]) left = mid + 1; // Single element is in the right half
                else right = mid - 1; // Single element is in the left half or at mid
            }
        }

        // left will be at the single element
        return nums[left];
    }
}
```

```java
public class Solution {
    public int singleNumber(int[] nums) {
        int result = 0;

        // XOR all elements in the array
        for (int num : nums) result ^= num; // XOR operation

        // The result now holds the single element that appears only once
        return result;
    }
}
```
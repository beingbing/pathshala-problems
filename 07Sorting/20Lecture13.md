# Merge Process
## Problem
You are given two integer arrays a1 and a2, sorted in non-decreasing order, and two integers m and n. a1 has a length of m + n, with its first m elements containing valid values and the rest filled with 0s to accommodate merging. a2 has a length of n, containing n valid values. Merge the two arrays into a single sorted array in-place, with the result stored in a1. Achieve this in O(m + n) time.

Constraints:
- a1.length == m + n
- a2.length == n
- 0 <= m, n <= 200
- 1 <= m + n <= 200
- -10⁹ <= a1[i], a2[j] <= 10⁹

### Solution
### Key Insights:
1. **Reverse Filling**: Since `a1` has enough space to accommodate the merged array, and the two arrays are sorted, we can merge them by starting from the end of both arrays. This avoids the need to shift elements in `a1`.
2. **Two Pointer Technique**: Use two pointers to track the current largest element in `a1` (excluding the extra zeroes) and `a2`. Place the larger of the two at the end of `a1`.
3. **Remaining Elements**: Once one array is exhausted, the other array's elements will already be in sorted order, so they can be copied directly.

### Deduction of Idea:
1. Starting from the **largest elements** in both arrays reduces the complexity of placing elements.
2. By reversing the direction (working from end to start), we utilize the extra space in `a1` efficiently without additional shifting.
3. Intuition for this approach comes from recognizing that appending elements from the end avoids overlap.

### Developing Intuition:
1. **Understand the Problem Constraints**: `a1` already has the extra space for the result. Both arrays are sorted.
2. **Visualize a Merge Process**: Imagine merging two piles of sorted cards, and notice how comparing the largest elements works best.
3. **Reverse Merge**: Use the largest available slot at the end of `a1`.

### Code
```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // Pointers for nums1, nums2, and the end of merged array
        int i = m - 1;  // Last valid element in nums1
        int j = n - 1;  // Last element in nums2
        int k = m + n - 1;  // Last position in nums1
        
        // Merge arrays from the end
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        
        // If nums2 has remaining elements, copy them
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
        // No need to copy nums1 elements as they are already in place
    }
}
```

### Complexity:
1. **Time**: O(m + n), as each element is processed once.
2. **Space**: O(1), as no extra space is used.

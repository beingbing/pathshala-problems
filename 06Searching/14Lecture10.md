# kth smallest in array - 1
## Problem
Given an unsorted array with possible duplicates and an integer k, we need to find the k-th smallest element without modifying the array and without using additional space.

#### Example
**Input**: `k = 6`, `a[] = {40, 10, 10, 30, 40, 20, 50, 70, 50}`  
**Output**: `40`

## Solution
### Approach
2. **Objective**:
    - Rather than sorting, use a method called **"Binary Search on Answer"** by leveraging a property of array elements to guide the search.
3. **Insight**:
    - In a sorted array, the k-th smallest element would sit at index `k - 1`.
    - We can determine the position of a candidate element by counting how many elements are smaller than it.
    - Using this count, we can deduce whether a candidate might be the k-th smallest.

### Strategy: Counting Smaller and Equal Elements
- For a candidate element `x`, count:
    - **`smaller`**: The number of elements strictly smaller than `x`.
    - **`equal`**: The number of elements equal to `x`.

- If the count of `smaller` elements plus `equal` elements encompasses `k`, and `smaller` alone is less than `k`, then `x` is the k-th smallest element.

### Code
```java
public class KthSmallestFinder {
    public int kthSmallest(int[] arr, int k) {
        int n = arr.length;
        
        for (int i = 0; i < n; i++) {
            int smaller = 0, equal = 0;

            // Count smaller and equal elements
            for (int j = 0; j < n; j++) {
                if (arr[j] < arr[i]) smaller++;
                else if (arr[j] == arr[i]) equal++;
            }

            // Check if current element is the k-th smallest
            int total = smaller + equal;
            if (total >= k && smaller < k) return arr[i];
        }
        
        // If no such element is found (should not happen in a valid input)
        throw new IllegalArgumentException("Invalid input: k is out of range");
    }

    public static void main(String[] args) {
        KthSmallestFinder finder = new KthSmallestFinder();
        int[] arr = {40, 10, 10, 30, 40, 20, 50, 70, 50};
        int k = 6;
        System.out.println("The " + k + "-th smallest element is " + finder.kthSmallest(arr, k));
    }
}
```

### Complexity and Considerations
- **Time Complexity**: `O(n^2)`, as we calculate smaller and equal counts for each element.
- **Space Complexity**: `O(1)`, meeting the constraint of no additional space usage.

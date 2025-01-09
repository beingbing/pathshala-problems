# merge sort
## Problem
Given an array arr of size n. Sort the array using merge sort algorithm.

### Solution
### Key Insights:
1. Merge Sort is a divide-and-conquer algorithm that:
   - Divides the array into two halves recursively until each half consists of a single element.
   - Merges the two halves back in a sorted manner.

2. **Divide and Conquer**:
    - Recursively splitting the array into halves reduces the problem into smaller, solvable sub-problems.
    - Merging leverages the sorted nature of the two halves and avoids redundant comparisons.

3. **Stable Sorting**: Merge Sort maintains the relative order of elements with equal values, making it ideal for applications requiring stability.

### Approach
1. **Recursion**: naturally handles the breakdown and reassembly of the array.
2. **Divide**: Split the array into two halves until only single elements remain (base case) simplifies the problem.
3. **Conquer**: Recursively sort each half.
4. **Merge**: Visualize merging as weaving two sorted lists together, always picking the smaller value.

### Code
```java
import java.util.Scanner;

public class MergeSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input size of array
        int n = sc.nextInt();
        int[] arr = new int[n];

        // Input array elements
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Perform merge sort
        mergeSort(arr, 0, n - 1);

        // Print sorted array
        for (int num : arr) {
            System.out.print(num + " ");
        }
        sc.close();
    }

    // Recursive merge sort function
    private static void mergeSort(int[] arr, int left, int right) {
        if (left == right) return;

        // Find the midpoint
        int mid = left + (right - left) / 2;

        // Recursively sort the left half
        mergeSort(arr, left, mid);

        // Recursively sort the right half
        mergeSort(arr, mid + 1, right);

        // Merge the two sorted halves
        merge(arr, left, mid, right);
    }

    // Merge two sorted subarrays
    private static void merge(int[] arr, int left, int mid, int right) {
        // Sizes of two subarrays
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Temporary arrays
        int[] leftArr = new int[n1];
        int[] rightArr = new int[n2];

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
        for (int i = 0; i < n2; i++) rightArr[i] = arr[mid + 1 + i];

        // Merge the temporary arrays back into arr
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
            if (leftArr[i] <= rightArr[j]) arr[k++] = leftArr[i++];
            else arr[k++] = rightArr[j++];

        // Copy any remaining elements from leftArr
        while (i < n1) arr[k++] = leftArr[i++];

        // Copy any remaining elements from rightArr
        while (j < n2) arr[k++] = rightArr[j++];
    }
}
```

### Complexity
- Time: O(n log n) for both recursive and iterative approaches.
- Space: O(n) for temporary array + O(log n) for the recursion stack.

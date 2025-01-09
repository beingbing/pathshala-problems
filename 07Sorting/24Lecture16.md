# Inversion Count
## Problem
Given an array of size n. Print the count of total number of inversions of the array. A pair (a[i],a[j]) is said to be in inversion if: a[i] > a[j] and i < j with 0 <= i, j < n

### Solution
### Key Insights:
1. This problem involves counting "out-of-order" elements in an array or comparing elements across two sorted halves.
2. **Merge Sort Connection**: Merge Sort naturally process inversions during the merging step. If a[i] > a[j], all elements from i to the midpoint are greater than a[j], contributing to the inversion count.
3. A modified Merge Sort can efficiently count inversions. During merging, whenever an element from the right array is placed before elements from the left, it indicates inversions for all remaining elements in the left array. This counts how many elements in the left half are greater than a particular element in the right half.
4. The inversion count measures the "degree of unsortedness." A higher count means the array is more unsorted.

### Code
```java
import java.util.Scanner;

public class CountInversions {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Number of test cases
        int T = sc.nextInt();

        while (T-- > 0) {
            // Input size of the array
            int n = sc.nextInt();
            int[] arr = new int[n];

            // Input array elements
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            // Count inversions using merge sort
            long inversionCount = mergeSortAndCount(arr, 0, n - 1);

            // Print the result
            System.out.println(inversionCount);
        }
        sc.close();
    }

    // Merge Sort function to count inversions
    private static long mergeSortAndCount(int[] arr, int left, int right) {
        long count = 0;

        if (left < right) {
            // Find the midpoint
            int mid = left + (right - left) / 2;

            // Count inversions in the left half
            count += mergeSortAndCount(arr, left, mid);

            // Count inversions in the right half
            count += mergeSortAndCount(arr, mid + 1, right);

            // Count inversions during merge
            count += mergeAndCount(arr, left, mid, right);
        }

        return count;
    }

    // Merge function to count inversions during merging
    private static long mergeAndCount(int[] arr, int left, int mid, int right) {
        // Sizes of two subarrays
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Temporary arrays
        int[] leftArr = new int[n1];
        int[] rightArr = new int[n2];

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++) {
            leftArr[i] = arr[left + i];
        }
        for (int i = 0; i < n2; i++) {
            rightArr[i] = arr[mid + 1 + i];
        }

        // Merge the two subarrays and count inversions
        int i = 0, j = 0, k = left;
        long count = 0;

        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
                // Count inversions: all remaining elements in leftArr are greater
                count += (n1 - i);
            }
        }

        // Copy remaining elements from leftArr
        while (i < n1) {
            arr[k++] = leftArr[i++];
        }

        // Copy remaining elements from rightArr
        while (j < n2) {
            arr[k++] = rightArr[j++];
        }

        return count;
    }
}
```

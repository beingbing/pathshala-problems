# Bubble Sort
Bubble Sort is a simple comparison-based sorting algorithm. It is named for the way larger elements "bubble" to the top (or right) of the array during successive passes through the array.

Without bubble terminology, it can be said that, in a single pass through the array, we are assessing all subarrays of size 2, and reverse them if they are found unsorted.

## Concept
- **Bubbling:** One complete pass through the array, where adjacent elements are compared and swapped if they are out of order.
- **Collision:** During a bubbling pass, adjacent elements "collide" to ensure relative order.
- After each pass, the largest unsorted element settles in its correct position in the sorted portion of the array.
- In the worst case, `n-1` passes are required to sort an array of `n` elements.

## Characteristics
1. **Best-case Time Complexity**: `O(n)` (when the array is already sorted).
2. **Worst-case Time Complexity**: `O(n^2)` (when the array is sorted in reverse order).
3. **Space Complexity**: `O(1)` (in-place sorting).
4. **Stability**: Bubble Sort is a stable sorting algorithm.

## Algorithm Steps
1. Start from the beginning of the array.
2. Compare adjacent elements. If they are in the wrong order, swap them.
3. Repeat the process for `n-1` passes, progressively reducing the range of comparison as the largest elements are sorted.
4. If no swaps occur during a bubbling pass, the array is already sorted, and further passes can be skipped.

## Code
```java
import java.util.Arrays;

public class BubbleSort {
    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            boolean swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) { // Swap if elements are out of order
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            // If no elements were swapped in this pass, array is sorted
            if (!swapped) break;
        }
    }

    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        System.out.println("Original Array: " + Arrays.toString(arr));
        bubbleSort(arr);
        System.out.println("Sorted Array: " + Arrays.toString(arr));
    }
}
```

## Variation: Trouble Sort
A modified version of Bubble Sort to sort odd and even indices independently. This involves comparing and swapping elements that are two indices apart.

### Concept
1. Instead of comparing adjacent elements, compare elements at indices `j` and `j+2`.
2. Swap the pair if they are out of order.

### Implementation in Java

```java
import java.util.Arrays;

public class TroubleSort {
    public static void troubleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            boolean swapped = false;
            for (int j = 0; j < n - i - 2; j++) { // Compare elements two indices apart
                if (arr[j] > arr[j + 2]) { // Reverse if out of order
                    int temp = arr[j];
                    arr[j] = arr[j + 2];
                    arr[j + 2] = temp;
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }

    public static void main(String[] args) {
        int[] arr = {9, 7, 5, 3, 1, 8, 6, 4, 2, 0};
        System.out.println("Original Array: " + Arrays.toString(arr));
        troubleSort(arr);
        System.out.println("Trouble Sorted Array: " + Arrays.toString(arr));
    }
}
```

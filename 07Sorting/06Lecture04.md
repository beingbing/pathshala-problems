# Sorting
Sorting algorithms are broadly classified into two types:
1. **Comparison-based:** Insertion Sort, Bubble Sort, Merge Sort, Quick Sort
2. **Non-comparison-based:** Count Sort, Radix Sort
Here, focus is on **comparison-based sorting**, where sorting decisions are made by comparing elements.

## Key Insight into Comparison-based Sorting
- **Time Complexity**: The worst-case time complexity for comparison-based sorting is O(n^2)
- **Optimal Limit**: No comparison-based sorting algorithm can achieve better than O(n log n) in the worst case.
- **Examples**: Bubble Sort, Selection Sort, and Insertion Sort are O(n^2) algorithms.

## Insertion Sort
### Concept
Insertion Sort builds the sorted array one element at a time by inserting each element into its correct position.
- For each element, the algorithm compares it with the elements before it and shifts larger elements one position to the right.
- The process continues until the correct position for the current element is found.

### Characteristics
1. **Best-case Time Complexity**: O(n) (when the array is already sorted).
2. **Worst-case Time Complexity**: O(n^2) (when the array is sorted in reverse order).
3. **Average-case Time Complexity**: O(n^2) (depends on the degree of unsortedness).
4. **Space Complexity**: O(1) (in-place sorting).
5. **Stability**: Insertion Sort is stable unless implemented incorrectly (e.g., comparing with >= instead of >).

### Code
```java
import java.util.Arrays;

public class InsertionSort {

    public static void insertionSort(int[] a) {
        int n = a.length;
        for (int j = 1; j < n; j++) { // Start from the second element
            int key = a[j];
            int i = j - 1;
            
            // Shift larger elements one position to the right
            while (i >= 0 && a[i] > key) {
                a[i + 1] = a[i];
                i--;
            }
            a[i + 1] = key; // Insert the key into its correct position
        }
    }

    public static void main(String[] args) {
        int[] arr = {12, 11, 13, 5, 6};
        System.out.println("Original Array: " + Arrays.toString(arr));
        insertionSort(arr);
        System.out.println("Sorted Array: " + Arrays.toString(arr));
    }
}
```

### Understanding Stability
Insertion Sort is stable because it preserves the relative order of equal elements.
- Example: `[4a, 2, 4b, 3]` will result in `[2, 3, 4a, 4b]`.
- Stability can break if `>=` is used in the condition:
```
  while (i >= 0 && arr[i] >= key) { 
      arr[i + 1] = arr[i]; 
      i--;
  }
```

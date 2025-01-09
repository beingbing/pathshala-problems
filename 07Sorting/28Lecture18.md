# Quick Sort Algorithm
Quick Sort is a comparison-based **divide and conquer sorting algorithm** that is efficient, in-place, and widely used in practice.

## Key Insights:
1. **Partitioning**:
    - The array is divided into two parts based on a pivot element.
    - Elements smaller than the pivot are moved to the left, and elements larger are moved to the right.
2. **Divide and Conquer**:
    - After partitioning, the pivot is at its correct sorted position.
    - Recursively sort the subarrays to the left and right of the pivot.
3. **Efficiency**: Quick Sort is faster in practice compared to merge sort due to its in-place sorting around pivot by avoiding merging (as in merge sort), hence reducing memory overhead. Choosing a good pivot is crucial for ensuring discussed efficiency.
4. **Pivot Choice**: Use a random pivot or median-of-three heuristic for better performance. A poor pivot can degrade performance.

### Algorithm Intuition:
1. **Choose a Pivot**: Select a pivot element (commonly the last element, first element, or a random element).
2. **Partition**: Rearrange the array such that elements smaller than the pivot are on its left and elements larger are on its right. Return the final position of the pivot.
3. **Recursive Sorting**: Apply the same process to the left and right subarrays.

### Java Implementation:
```java
public class QuickSort {

    // Function to sort an array using Quick Sort
    public void quickSort(int[] arr, int low, int high) {
        if (low >= high) return;

        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }

    // Partition function to rearrange elements around the pivot
    private int partition(int[] arr, int low, int high) {
        int pivot = arr[high]; // Pivot element
        int i = low; // Index of the smaller element

        for (int j = low; j < high; j++) {
            // If the current element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                swap(arr, i, j); // Swap elements
                i++; // Increment the index of the smaller element
            }
        }
        
        // Place pivot in the correct position
        swap(arr, i, high);
        return i;
    }

    // Utility function to swap two elements
    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Main method to test the Quick Sort implementation
    public static void main(String[] args) {
        QuickSort sorter = new QuickSort();
        int[] arr = {10, 7, 8, 9, 1, 5};
        sorter.quickSort(arr, 0, arr.length - 1);
        
        // Print the sorted array
        for (int num : arr) System.out.print(num + " ");
    }
}
```

### Complexity
1. **Time**:
    - **Best and Average Case**: O(n log n), achieved when the pivot divides the array approximately in half at each step.
    - **Worst Case**: O(n^2), occurs when the pivot is always the smallest or largest element (e.g., sorted array with first/last pivot).

2. **Space**: O(log n) for the recursion stack in the best/average case; O(n) in the worst case.

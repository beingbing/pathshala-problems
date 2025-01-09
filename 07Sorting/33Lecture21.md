 # count sort

Count Sort is a non-comparison-based stable sorting algorithm suitable for sorting elements that can be mapped to integers within a specific range. It works efficiently when the range of the data (difference between maximum and minimum elements) is not significantly larger than the number of elements to be sorted.

## How Count Sort Works
1. **Determine the Range of Elements**: Identify the minimum and maximum values in the input array to compute the range of the data.
2. **Count Frequencies**: Create a frequency array (`count[]`) where each index represents an element in the range, and the value at each index represents the count of that element in the input array.
3. **Compute Cumulative Frequencies**: Transform the `count[]` array to store the cumulative count. This determines the position of each element in the sorted output.
4. **Build the Output Array**: Iterate through the input array in reverse to maintain the stability of the sort (important for applications where the order of equal elements should remain the same). Use the cumulative counts to place elements into their correct positions in the output array.
5. **Copy Back to Original Array (if needed)**: Copy the sorted elements from the output array back to the input array if the sorting is to be done in place.

## Properties of Count Sort
- **Time**: O(n + k), where n is the number of elements and k is the range of the input.
- **Space**: O(n + k), for the count and output arrays.

## Code
```java
import java.util.Arrays;

public class CountSort {

    public static void countSort(int[] arr) {
        if (arr.length == 0) return;

        // Step 1: Find the range of the input
        // automatically accommodates -ve elements as well
        int min = Arrays.stream(arr).min().getAsInt();
        int max = Arrays.stream(arr).max().getAsInt();
        int range = max - min + 1;

        // Step 2: Create and populate the count array
        int[] count = new int[range];
        for (int num : arr) count[num - min]++;

        // Step 3: Compute cumulative count
        for (int i = 1; i < count.length; i++) count[i] += count[i - 1];

        // Step 4: Sort the elements into an output array
        int[] output = new int[arr.length];
        // iterating input array in reverse ensures stability
        for (int i = arr.length - 1; i >= 0; i--) {
            int num = arr[i];
            output[count[num - min] - 1] = num;
            count[num - min]--;
        }

        // Step 5: Copy sorted elements back to the original array
        System.arraycopy(output, 0, arr, 0, arr.length);
    }

    public static void main(String[] args) {
        int[] arr = {4, 2, 2, 8, 3, 3, 1};
        System.out.println("Original array: " + Arrays.toString(arr));
        countSort(arr);
        System.out.println("Sorted array:   " + Arrays.toString(arr));
    }
}
```

### Example Execution
#### Input:
\[4, 2, 2, 8, 3, 3, 1\]
#### Steps:
1. **Find Range**: \(min = 1, max = 8, range = 8 - 1 + 1 = 8\).
2. **Count Array**: \([0, 1, 2, 0, 1, 0, 0, 1]\).
3. **Cumulative Count**: \([0, 1, 3, 3, 4, 4, 4, 5]\).
4. **Output Array**: \([1, 2, 2, 3, 3, 4, 8]\).

# Radix Sort Algorithm
Radix Sort is a non-comparison-based sorting algorithm that sorts integers or strings by processing individual digits or characters. It sorts elements by their least significant digit (LSD) to the most significant digit (MSD) (or vice versa, depending on implementation). It is efficient for data with fixed-length keys, like integers or strings. It is efficient when the range of digits/characters of elements is not excessively large. Its stable algorithm, as it relies on stable sub-sorts (like Count Sort).

## How Radix Sort Works
1. **Determine the Range and Max Number of Digits**: Identify the maximum value in the input to determine how many digits need to be processed.
2. **Sort by Each Digit**: Perform a stable sort (e.g., Count Sort) for each digit, starting from the least significant digit (LSD) to the most significant digit (MSD).
3. **Repeat for Each Position**:
    - For integers, the positions are powers of 10 (1s, 10s, 100s, etc.).
    - For strings, positions correspond to individual character indices.

## Properties of Radix Sort
- **Time**: O(d * (n + b)), where:
  - d is the number of digits in the largest number.
  - n is the number of elements.
  - b is the base (e.g., 10 for decimal numbers).
- **Space**: O(n + b), for the temporary arrays used during each sorting pass.

## Code
```java
import java.util.Arrays;

public class RadixSort {

    // Function to get the maximum value in the array
    private static int getMax(int[] arr) {
        int max = arr[0];
        for (int num : arr) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }

    // A stable sort (Count Sort) for a specific digit
    private static void countSortForDigit(int[] arr, int exp) {
        int n = arr.length;
        int[] output = new int[n];
        int[] count = new int[10]; // Base 10 for decimal digits

        // Step 1: Count occurrences of each digit at current place value
        for (int num : arr) {
            int digit = (num / exp) % 10;
            count[digit]++;
        }

        // Step 2: Compute cumulative count
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Step 3: Place elements into the output array in stable order
        for (int i = n - 1; i >= 0; i--) {
            int num = arr[i];
            int digit = (num / exp) % 10;
            output[count[digit] - 1] = num;
            count[digit]--;
        }

        // Step 4: Copy sorted elements back to the original array
        System.arraycopy(output, 0, arr, 0, n);
    }

    // Main Radix Sort function
    public static void radixSort(int[] arr) {
        if (arr.length == 0) return;

        // Step 1: Find the maximum number to determine the number of digits
        int max = getMax(arr);

        // Step 2: Perform Count Sort for each digit (1s, 10s, 100s, etc.)
        for (int exp = 1; max / exp > 0; exp *= 10) {
            countSortForDigit(arr, exp);
        }
    }

    public static void main(String[] args) {
        int[] arr = {170, 45, 75, 90, 802, 24, 2, 66};
        System.out.println("Original array: " + Arrays.toString(arr));
        radixSort(arr);
        System.out.println("Sorted array:   " + Arrays.toString(arr));
    }
}
```
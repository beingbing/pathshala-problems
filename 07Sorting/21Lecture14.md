# Applications Of Merge Process
## Problem 1
Given a sorted integer array, return an array of the squares of each number, sorted in non-decreasing order. Solve the problem in O(n) time.

Constraints:
- 1 <= a.length <= 10⁴
- -10⁴ <= a[i] <= 10⁴
- array is sorted in non-decreasing order.

### Solution
### Key Insights:
1. **Negative Numbers and Squaring**: Negative numbers, when squared, become positive, and their order may change relative to positive numbers.
2. **Two Pointer Technique**: Since the input array is sorted, the largest squared value will be at either the extreme left or right of the array. By comparing the absolute values of the elements at both ends, we can determine the largest square and place it at the end of the result array.
3. **Reverse Placement**: To avoid extra sorting, populate the result array from the end while iterating from both sides.

### Code
```java
class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];  // Result array to store sorted squares
        int left = 0;  // Pointer to start of nums
        int right = n - 1;  // Pointer to end of nums
        int index = n - 1;  // Fill the result array from the end
        
        // Compare absolute values from both ends and fill result array
        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            
            if (leftSquare > rightSquare) {
                result[index] = leftSquare;
                left++;  // Move left pointer
            } else {
                result[index] = rightSquare;
                right--;  // Move right pointer
            }
            index--;  // Move to the next position in result
        }
        
        return result;
    }
}
```

### Complexity:
- **Time**: O(n), as each element is processed exactly once.
- **Space:** O(n), result array.

## Problem 2
Given a sorted integer array of size N and three integers `A`, `B`, and `C` (`A ≠ 0`), compute a new array where each element is:  
new_array[i] = A * arr[i]^2 + B * arr[i] + C
Return the new array sorted in ascending order.

Constraints:
- 1 <= T <= 5
- 1 <= N <= 10^6
- -10^5 <= arr[i] <= 10^5

### Solution
### Key Insights:
1. **Quadratic Transformation**: The transformation function f(x) = A * x^2 + B * x + C is a quadratic equation. Its behavior is determined by the value of A:
   - If A > 0, the parabola opens upwards.
   - If A < 0, the parabola opens downwards.
2. The vertex of the parabola occurs at x = -(B)/(2A), dividing the array into two parts: one where the function is increasing and another where it is decreasing.
3. **Two Pointers**: Using the sorted property of the input array and the symmetry of the quadratic function, the smallest or largest values (depending on A) will occur at the ends of the array. This makes the two-pointer technique optimal.
4. Depending on whether A > 0 or A < 0, traverse the array using two pointers to construct the result array either in reverse or directly.

### Deduction of Idea:
1. Since the input array is sorted, the transformation results in either a partially sorted or reverse-sorted pattern around the vertex.
2. By comparing transformed values at both ends, we can efficiently populate the result array in O(N), avoiding the need for an explicit sort.

### Developing Intuition:
1. **Understanding the Shape**:
    - Visualize how the quadratic equation transforms the input.
    - Use the parabola's vertex to divide the input array into manageable segments.
2. **Optimal Construction**:
    - Recognize that comparing values at the ends reduces unnecessary operations and avoids resorting.

### Steps to Approach:
1. **Transform the Array**:
    - Apply f(x) to each element in the input array.
2. **Two Pointers for Sorting**:
    - Use two pointers (start and end) to compare transformed values.
    - Populate the result array from the smallest to largest (or reverse, depending on A).
3. **Iterate for Each Test Case**:
    - Process each test case independently and print the results.

### Algorithm Design Reasoning:
- The two-pointer technique is crucial due to the sorted input.
- Quadratic properties simplify determining the traversal direction.


### Code
```java
import java.util.Scanner;

public class QuadraticTransform {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();  // Number of test cases

        while (T-- > 0) {
            // Read A, B, C
            int A = sc.nextInt();
            int B = sc.nextInt();
            int C = sc.nextInt();

            // Read array size
            int N = sc.nextInt();
            int[] arr = new int[N];

            // Read array elements
            for (int i = 0; i < N; i++) {
                arr[i] = sc.nextInt();
            }

            // Get sorted transformed array
            int[] result = sortedTransformedArray(arr, A, B, C);

            // Print result
            for (int num : result) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
        sc.close();
    }

    // Function to compute sorted transformed array
    private static int[] sortedTransformedArray(int[] arr, int A, int B, int C) {
        int N = arr.length;
        int[] result = new int[N];
        int left = 0, right = N - 1;
        int index = (A > 0) ? N - 1 : 0;  // Start filling from the end if A > 0

        // Two-pointer approach
        while (left <= right) {
            int leftVal = applyQuadratic(arr[left], A, B, C);
            int rightVal = applyQuadratic(arr[right], A, B, C);

            if (A > 0) {
                // For upward parabola, place larger values at the end
                if (leftVal > rightVal) {
                    result[index--] = leftVal;
                    left++;
                } else {
                    result[index--] = rightVal;
                    right--;
                }
            } else {
                // For downward parabola, place smaller values at the start
                if (leftVal < rightVal) {
                    result[index++] = leftVal;
                    left++;
                } else {
                    result[index++] = rightVal;
                    right--;
                }
            }
        }
        return result;
    }

    // Apply the quadratic transformation
    private static int applyQuadratic(int x, int A, int B, int C) {
        return A * x * x + B * x + C;
    }
}
```

### Complexity Analysis:
- **Time:** O(N)
- **Space**: O(1)

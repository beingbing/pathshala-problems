# Introduction to Time Complexity
**Question**: How can we measure the time taken by code to execute?

## Concept
To make execution time independent of hardware, we measure it by counting the number of operations, which correlates directly with the size of the input. This allows us to express runtime as a function of input size, focusing on how the time grows with larger inputs.

## Example Analysis
Let's analyze a simple code example to calculate time complexity:
```java
public class TimeComplexityExample {
    public static void main(String[] args) {
        int n = 10; // example input size
        int[] arr = new int[n];
        int sum = 0, c = 0;  // constant time operations (independent of n)

        for (int i = 0; i < n; i++) {  // n iterations for input size n
            sum += arr[i];             // constant time addition
            c++;                       // constant time increment
        }

        System.out.println("Sum: " + sum + ", Counter: " + c);
    }
}
```

### Step-by-Step Breakdown
1. **Constant Operations**:
    - Declaring variables and initializing them (`int sum = 0, c = 0;`) take constant time, independent of `n`.
    - **Time for this part**: `c_1` (constant).
2. **Loop Operations**:
    - The `for` loop iterates `n` times, where each iteration:
        - Adds an array element to `sum` (`sum += arr[i];`).
        - Increments `c` by 1 (`c++;`).
    - Both operations within the loop are constant-time operations.
    - **Total time for the loop**: `n * c_2`, where `c_2` is constant.

### Total Time Complexity
The total time is:
```
Total Time = c_1 + n * c_2
```
As `n` grows, the constant terms become negligible, and the runtime grows linearly with `n`. Therefore, the time complexity is **O(n)**.

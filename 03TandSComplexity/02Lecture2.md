# Time Complexity, Order of Expressions, and Recurrence Relations
In time complexity analysis, we aim to understand the performance of algorithms in terms of input size. For a function representing operations as `an^3 + bn^2 + cn + d`, where `a`, `b`, `c`, and `d` are constants, the **order** for large `n` is driven by the term with the highest power. Here, it is `O(n^3)`.

## Example Problem: Nested Loops and Order of Expressions
### Problem
Calculate the time complexity for the following code:
```java
public class TimeComplexityExample {
    public static void main(String[] args) {
        int n = 5; // example input size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                System.out.println(i + " " + j);
            }
        }
    }
}
```
### Iterative Analysis
1. **Operation Breakdown**:
    - The outer loop runs `n` times.
    - The inner loop runs `i+1` times for each `i`.
    - Total operations = `1 + 2 + 3 + ... + n = n(n+1)/2 = O(n^2)` for large `n`.
2. **Final Complexity**: `O(n^2)`

### Recursive Analysis
For the nested loops, we observe that each level introduces one more operation, forming the recurrence:
```
T(n) = T(n-1) + O(n)
```
Expand this relation by Substituting `T(n-1) = T(n-2) + (n-1)`:
```
T(n) = T(n-2) + (n-1) + n
```
Further substitution will make it to reach:
```
T(n) = T(0) + 1 + 2 + ... + n = n(n+1)/2 = O(n^2)
```
As T(0) is time taken by code when n = 0, which will be 0.

## Understanding Recurrence Relations
Recurrence relations describe the time complexity of recursive algorithms. A recurrence relation links the time complexity of a problem with that of a smaller subproblem. Hence, Time Complexity of main problem = Time Complexity of smaller sub problem + some constant operations time
### Example 1: Simple Summation
Consider:
```cpp
int arr[n];
int sum = 0;
for (int i = 1; i < n; i++) {
    sum += arr[i];
}
```
This has a recurrence relation:
```
T(n) = T(n-1) + O(1)
```
Expand this relation by substituting `T(n-1) = T(n-2) + O(1)`:
```
T(n) = T(n-2) + 2 * O(1)
```
Further substitution will make it to reach:
```
T(n) = T(0) + n * O(1) = O(n)
```
Since T(0) = 0, the final complexity is T(n) = O(n).

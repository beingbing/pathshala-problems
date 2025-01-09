# Finding Minimum XOR Between Two Elements
## Problem
Given an array of size `n`, find the minimum XOR value between any two distinct elements `a[i]` and `a[j]`, where `i != j`

### Brute-Force Approach
#### Explanation
1. Compute XOR for every possible pair `(arr[i], arr[j])`
2. Keep track of the minimum XOR value encountered during the iterations.

#### Complexity
- **Time**: `O(n^2)` (due to the nested loops)
- **Space**: `O(1)`

#### Code
```java
public static int findMinXORBruteForce(int[] arr) {
    int n = arr.length;
    int ans = Integer.MAX_VALUE;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = Math.min(ans, arr[i] ^ arr[j]);
        }
    }
    return ans;
}
```

### Optimized Approach
#### Key Insight
The XOR value between two numbers is determined by the position of the most significant differing bit.
- To minimize `a[i] ^ a[j]`, we want two numbers `a[i]` and `a[j]` that are as close as possible in value.
- Sorting the array ensures that the closest values appear adjacent to each other.

#### Complexity
- **Time**: `O(n log n)` (due to sorting).
- **Space**: `O(1)`

#### Code
```java
import java.util.Arrays;

public class MinimumXOR {
    public static int findMinXOR(int[] arr) {
        Arrays.sort(arr); // Sort the array
        int n = arr.length;
        int ans = Integer.MAX_VALUE;

        for (int i = 0; i < n - 1; i++) {
            ans = Math.min(ans, arr[i] ^ arr[i + 1]);
        }
        return ans;
    }
}
```

# Processing Range Queries
## Problem
You are given an array of size n, initialized with all elements as zero. You also have q queries, where each query specifies two indices: a starting index l and an ending index r. For each query, increment all elements in the subarray a[l] to arr[r] by +1. Return the final state of the array after processing all queries.

### Solution
#### Brute-Force Solution:
1. For each query, iterate over the specified range from l to r.
2. Increment each element within this range.
3. Repeat for all q queries.
4. Time Complexity: Worst case: O(q * n), where n is the size of the array.  

#### Optimized Solution:
To optimize, we can reduce the time complexity by using prefix/suffix sums to propagate changes. The idea is to:
1. Increment the starting index l by +1 for every query.
2. Decrement the index r+1 by -1 (if it is within bounds).
3. Compute the prefix sum of the array to distribute these changes across the array.
4. The opposite of this can be done with the suffix sum.

#### Complexity:
- Marking updates: O(q)
- Prefix sum computation: O(n)
- Total: O(n + q)

## Java Implementation
```java
import java.util.Arrays;

public class RangeQueries {
    // Function to process range queries and return the final array
    public static int[] processQueries(int n, int[][] queries) {
        int[] aux = new int[n + 1];

        // Mark increments and decrements in the auxiliary array
        for (int[] query : queries) {
            int l = query[0];
            int r = query[1];
            aux[l] += 1;
            if (r + 1 < n) {
                aux[r + 1] -= 1;
            }
        }

        // Compute the prefix sum to get the final state of the array
        int[] result = new int[n];
        result[0] = aux[0];
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] + aux[i];
        }

        return result;
    }

    public static void main(String[] args) {
        int n = 5; // Size of the array
        int[][] queries = {
            {0, 2}, // Increment arr[0] to arr[2] by 1
            {1, 4}, // Increment arr[1] to arr[4] by 1
            {2, 3}  // Increment arr[2] to arr[3] by 1
        };

        int[] result = processQueries(n, queries);
        System.out.println("Final Array: " + Arrays.toString(result));
    }
}
```

### Generalization for Arbitrary Values:
The problem can be extended to handle queries that specify a value k to increment the subarray.

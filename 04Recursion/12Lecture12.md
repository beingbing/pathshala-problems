# Generating All Subsets of a Set Using Bit Masking
## Problem
Given an integer array `nums` with unique elements, generate all possible subsets (the power set) of `nums` using **bit masking**. Each subset must be unique, and the solution can be returned in any order.

## Solution
To generate all subsets (the power set) of an array using bit masking, we can leverage the binary representation of numbers to indicate the presence or absence of elements in each subset.

### Key Concept: Bit Masking
Masking means hiding some information, hence, the bit masking signifies hiding/representing something in terms of bit.

**Bit masking** is an approach that uses binary representations to solve problems with two possible states (such as "include" or "exclude" an element). In this case:
- Each subset corresponds to a binary number, where each bit represents whether a specific element in `nums` is included (1) or excluded (0).
- For an array with `n` elements, each subset can be represented by a unique binary number from `0` to `2^n - 1`, giving `2^n` possible subsets.

### Steps to Approach the Problem

1. **Binary Representation as a Selector**:
    - Use integers from `0` to `(2^n - 1)` to represent every possible subset. For each integer, convert it to binary.
    - Each bit in the binary number indicates whether to include the element at that index in the subset.

2. **Construct Subsets Based on Bit Position**:
    - For each number, iterate over each bit from the least significant bit (LSB) to the most significant bit (MSB).
    - If the bit at position `j` is `1`, include `nums[j]` in the subset; otherwise, skip it.

3. **Complexity**:
    - **Time Complexity**: `O(2^n * n)` because there are `2^n` subsets and each subset takes `O(n)` time to construct.
    - **Space Complexity**: `O(2^n * n)` for storing the result.

4. **Edge Cases**:
    - **Empty Array**: Return `[[]]` because the only subset of an empty set is itself.
    - **Single Element**: Return `[[], [element]]` for a single-element array.
    - **Large `n`**: For large `n`, this algorithm's performance may become an issue since it scales exponentially.

### Explanation of Bit Manipulation

- `1 << j` shifts the number `1` left by `j` positions, setting the `j`-th bit to `1` (e.g., `1 << 2` gives `100` in binary).
- `mask & (1 << j)` checks if the `j`-th bit in `mask` is `1`. If so, it includes `nums[j]` in the subset.

### Code
```java
import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        int n = nums.length;
        int subsetCount = 1 << n; // 2^n
        List<List<Integer>> allSubsets = new ArrayList<>(subsetCount);

        // Iterate over all possible subsets
        for (int mask = 0; mask < subsetCount; mask++) {
            List<Integer> subset = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                if ((mask & (1 << j)) != 0) { // Check if the j-th bit is set
                    subset.add(nums[j]);
                }
            }
            allSubsets.add(subset);
        }
        return allSubsets;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {1, 3, 2};
        List<List<Integer>> subsets = solution.subsets(nums);
        for (List<Integer> subset : subsets) {
            System.out.println(subset);
        }
    }
}
```

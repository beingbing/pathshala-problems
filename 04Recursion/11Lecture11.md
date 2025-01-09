# Generating All Subsets of a Set
## Problem Statement
Given an integer array `nums` with unique elements, generate all possible subsets (the power set) of `nums`. Each subset must be unique, and the solution can be returned in any order.

## Solution
### Key Idea
To form each subset, we make a binary choice for each element in `nums`:
- **Include the element** or
- **Exclude the element**  

Using this inclusion-exclusion principle, we can form all possible combinations of the array elements. This approach produces a binary tree where each branch represents either including or excluding the current element, leading to `2^n` subsets.

### Code
#### Recursive Solution
```java
import java.util.ArrayList;
import java.util.List;

class Solution {
    private void generateSubsets(List<Integer> currentSubset, List<List<Integer>> result, int[] nums, int index) {
        if (index == nums.length) {
            result.add(new ArrayList<>(currentSubset));
            return;
        }
        // Include current element
        currentSubset.add(nums[index]);
        generateSubsets(currentSubset, result, nums, index + 1);
        
        // Exclude current element
        currentSubset.remove(currentSubset.size() - 1);
        generateSubsets(currentSubset, result, nums, index + 1);
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        generateSubsets(new ArrayList<>(), result, nums, 0);
        return result;
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
#### Iterative Solution
```java
import java.util.ArrayList;
import java.util.List;

class IterativeSolution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        result.add(new ArrayList<>()); // start with the empty subset
        for (int num : nums) {
            int size = result.size();
            for (int i = 0; i < size; i++) {
                List<Integer> newSubset = new ArrayList<>(result.get(i));
                newSubset.add(num);
                result.add(newSubset);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        IterativeSolution solution = new IterativeSolution();
        int[] nums = {1, 3, 2};
        List<List<Integer>> subsets = solution.subsets(nums);
        for (List<Integer> subset : subsets) {
            System.out.println(subset);
        }
    }
}
```
### Complexity Analysis
recursion tree diagram  will have at every level 2^i leaves, and n (size of subset) will be the height of recursion tree. Total number of function call will be equal to the total number of nodes of tree, which will be the sum of nodes at each level, which will be -
1 + 2 + 4 + 8 + ... + 2^(n-2) + 2^(n-1) + 2^n = 2^(n+1) - 1
so, total invocation calls are 2^n, but at each leave node, printing of complete subset will also happen which can be of size n for each leaf node.
- **Time Complexity**: `O(n * 2^n)`, due to creating `2^n` subsets and constructing each subset in `O(n)` time.
- **Space Complexity**: `O(n)`, for the recursion stack.

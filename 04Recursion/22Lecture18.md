# subset sum - 2
## Problem
Given an integer array of size `n` with distinct positive elements, and a target integer `sum`, find all distinct combinations of elements that add up to the target sum. An element can be considered multiple times to find the sum.

## Solution
### Key Insights
1. **Subset Sum Problem**:
    - Each element in the array can either be included or excluded in a subset, but if included, it can be included for more than one time.
    - To allow the same element to be reused, keep the index unchanged in recursive calls.
    - Since each subset's sum needs to match the given target, we can systematically keep a running total of the sum as we build each subset.
2. **Subset Sum Checking**:
    - If the subset sum matches the target, we add it to the result.
    - If the sum exceeds the target or all elements are processed, the subset is abandoned.

### Code
```java
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CombinationSumFinder {

    public List<List<Integer>> findCombinations(int[] nums, int targetSum) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums); // Ensures lexicographical order of output
        backtrack(nums, targetSum, 0, new ArrayList<>(), result);
        return result;
    }

    private void backtrack(int[] nums, int targetSum, int index, List<Integer> currentSubset, List<List<Integer>> result) {
        if (targetSum == 0) {
            result.add(new ArrayList<>(currentSubset)); // Found a valid combination
            return;
        }
        
        for (int i = index; i < nums.length; i++) {
            int num = nums[i];
            if (num > targetSum) break; // Prune branches where the current element exceeds targetSum
            currentSubset.add(num);
            backtrack(nums, targetSum - num, i, currentSubset, result); // Allow reuse of the current element
            currentSubset.removeLast(); // Backtrack step
        }
    }

    public static void main(String[] args) {
        CombinationSumFinder solver = new CombinationSumFinder();
        int[] nums = {2, 3, 5};
        int targetSum = 8;
        System.out.println(solver.findCombinations(nums, targetSum)); // Expected output: [[2, 2, 2, 2], [2, 3, 3], [3, 5]]
    }
}
```

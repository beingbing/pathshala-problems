# subset sum - 1
## Problem
Given an integer array of size `n` with distinct elements, and a target integer `sum`, find all subsets of the array whose elements add up to the target sum. Print these subsets in lexicographical order.

## Solution
### Key Insights
1. **Backtracking with Lexicographical Order**:
   - Sort the array to generate subsets in lexicographical order naturally.
   - When backtracking, each recursive call will proceed with elements in increasing order, which ensures the subsets appear in sorted order.
2. **Subset Sum Problem**:
    - Each element in the array can either be included or excluded in a subset
    - Since each subset's sum needs to match the given target, we can systematically keep a running total of the sum as we build each subset.
3. **Subset Sum Checking**:
   - If the subset sum matches the target, we add it to the result.
   - If the sum exceeds the target or all elements are processed, the subset is abandoned.

### Code
```java
import java.util.ArrayList;
import java.util.List;

public class SubsetSum {

   // Method to count subsets with given sum
   public int countSubsets(int[] nums, int targetSum) {
      return countSubsetsHelper(nums, targetSum, 0, 0);
   }

   private int countSubsetsHelper(int[] nums, int targetSum, int index, int currentSum) {
      // Base case: if we reached the target sum, we found a valid subset
      if (currentSum == targetSum) return 1;

      // If the current sum exceeds the target or we have no more elements, return 0
      if (index >= nums.length || currentSum > targetSum) return 0;

      // Recursive cases: include the current element or skip it
      int include = countSubsetsHelper(nums, targetSum, index + 1, currentSum + nums[index]);
      int exclude = countSubsetsHelper(nums, targetSum, index + 1, currentSum);

      return include + exclude; // Count of valid subsets
   }

    // Method to find all subsets with a given sum
    public List<List<Integer>> findSubsetsWithSum(int[] nums, int targetSum) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums); // Sort to ensure lexicographical order
        SortedBacktrack(nums, targetSum, 0, 0, new ArrayList<>(), result);
        return result;
    }

    private void backtrack(int[] nums, int targetSum, int index, int currentSum, List<Integer> currentSubset, List<List<Integer>> result) {
        // Base case: if current subset sum matches target, add it to result
        if (currentSum == targetSum) {
            result.add(new ArrayList<>(currentSubset));
            return;
        }
        
        // If current sum exceeds target or no elements are left, stop exploring this path
        if (currentSum > targetSum || index == nums.length) {
            return;
        }
        
        // Include the current element in the subset
        currentSubset.add(nums[index]);
        backtrack(nums, targetSum, index + 1, currentSum + nums[index], currentSubset, result);
        
        // Backtrack: remove the current element and try the next option
        currentSubset.remove(currentSubset.size() - 1);
        backtrack(nums, targetSum, index + 1, currentSum, currentSubset, result);
    }

   // Recursive helper method for backtracking
   private void SortedBacktrack(int[] nums, int targetSum, int start, int currentSum, List<Integer> currentSubset, List<List<Integer>> result) {
      if (currentSum == targetSum) {
         result.add(new ArrayList<>(currentSubset)); // Add a copy of the current subset
         return;
      }

      for (int i = start; i < nums.length; i++) {
         int num = nums[i];
         // Skip if currentSum + num exceeds the targetSum
         if (currentSum + num > targetSum) continue;

         // Include the current element
         currentSubset.add(num);
         backtrack(nums, targetSum, i + 1, currentSum + num, currentSubset, result);

         // Backtrack: remove the last added element to explore other options
         currentSubset.removeLast();
      }
   }

    public static void main(String[] args) {
        SubsetSum solver = new SubsetSum();
        int[] nums = {2, 3, 5, 6, 8, 10};
        int targetSum = 10;
//       System.out.println(solver.countSubsets(nums, targetSum)); // Expected output: Count of subsets with sum 10
        System.out.println(solver.findSubsetsWithSum(nums, targetSum)); // Expected output: Subsets with sum 10
    }
}
```

## Note
1. If an array is allowed to have negative and zero numbers as well apart from positive numbers, then do not terminate as soon as your running sum becomes equal to the target sum. Instead, record the current state as one candidate for answer and move further forward without returning until the complete array is iterated.

# lexicographical subsets printing

## Problem
Given an integer array `nums` with unique elements, generate all possible subsets (the power set) of `nums`. Each subset must be unique, and the solution should be returned in lexicographical order.

### Solution
#### Key Insights
1. **Subsets and Backtracking**:
   - Each element in `nums` can either be **included** or **excluded** in a subset. This naturally leads to a **binary decision tree** where each path through the tree represents a subset.
   - Backtracking allows us to explore all possible combinations by either including or skipping each element at each decision level.

2. **Lexicographical Order**:
   - Sorting `nums` before generating subsets ensures the subsets will be created in lexicographical order, simplifying the sorting process afterward.
   - By generating subsets in sorted order, we avoid having to sort them again.

#### Code
```java
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class PowerSetLexicographical {

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> currentSubset = new ArrayList<>();

        // Sort to ensure lexicographical order
        Arrays.sort(nums);
        
        // Start recursive backtracking
        backtrack(nums, 0, currentSubset, result);
        return result;
    }

    private void backtrack(int[] nums, int index, List<Integer> currentSubset, List<List<Integer>> result) {
        // Add current subset to result (lexicographical order ensured by sorted `nums`)
        result.add(new ArrayList<>(currentSubset));
        
        for (int i = index; i < nums.length; i++) {
            // Include nums[i] in the subset
            currentSubset.add(nums[i]);
            
            // Recursive call to explore further subsets with nums[i] included
            backtrack(nums, i + 1, currentSubset, result);
            
            // Backtrack: remove the last element before moving to the next iteration
            currentSubset.removeLast();
        }
    }

    public static void main(String[] args) {
        PowerSetLexicographical solver = new PowerSetLexicographical();
        int[] nums = {3, 1, 2};
        List<List<Integer>> result = solver.subsets(nums);
        System.out.println(result);
        // Expected Output: [[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]]
    }
}
```

#### Explanation of Key Steps
1. **Sorting**: `nums` is sorted first to guarantee that subsets will be generated in lexicographical order.
2. **Backtracking Function**:
    - At each recursive call, the function iterates over the elements from the `index` onward, ensuring no element is reused in the same subset.
    - After adding an element, the function proceeds recursively to include more elements in the subset.
3. **Backtracking Step**:
    - After exploring subsets that include a particular element, the function removes it, backtracking to explore subsets without that element.

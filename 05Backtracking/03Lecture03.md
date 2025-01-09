# permutations of a string - 3
## Problem
Given a string `s` in which characters can repeat, print all possible permutations of the string.

## Solution
- The total number of strings that can be generated are - !len / (!freq(a)*!freq(b)*...)
- need to remove duplicate subtrees originating out of duplicate characters

### Key Insights
1. **Character Frequency Count**: Using a frequency map (like a `HashMap` or an array for small character sets) allows us to efficiently track which characters are still available and avoid duplicate permutations by only using characters if they haven’t been exhausted.
2. **Backtracking**: By recursively building each permutation, adding characters as we go, we can backtrack (undo choices) and proceed with the next option. This approach ensures each permutation is unique and generated in a structured way.
3. **Optimization with Sorting**: Sorting the input string helps keep permutations in lexicographical order if required. Additionally, it allows us to terminate certain branches early.

### Code
```java
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class PermutationsWithDuplicates {

    public List<String> permuteUnique(String s) {
        List<String> result = new ArrayList<>();
        Map<Character, Integer> charCountMap = new HashMap<>();
        // Build frequency map
        for (char ch : s.toCharArray()) charCountMap.put(ch, charCountMap.getOrDefault(ch, 0) + 1);
        // Start backtracking
        backtrack(result, new StringBuilder(), charCountMap, s.length());
        return result;
    }
    
    private void backtrack(List<String> result, StringBuilder currentPermutation, Map<Character, Integer> charCountMap, int targetLength) {
        // Base case: when the permutation reaches target length, add to result
        if (currentPermutation.length() == targetLength) {
            result.add(currentPermutation.toString());
            return;
        }
        
        // Explore all characters in the frequency map
        for (Map.Entry<Character, Integer> entry : charCountMap.entrySet()) {
            char ch = entry.getKey();
            int count = entry.getValue();
            
            if (count <= 0) continue; // Use character if available
            
            currentPermutation.append(ch);
            charCountMap.put(ch, count - 1); // Reduce frequency
            // Recurse to build the next character in permutation
            backtrack(result, currentPermutation, charCountMap, targetLength);
            // Backtrack: remove character and restore frequency
            currentPermutation.deleteCharAt(currentPermutation.length() - 1);
            charCountMap.put(ch, count);
            
        }
    }

    public static void main(String[] args) {
        PermutationsWithDuplicates permuter = new PermutationsWithDuplicates();
        System.out.println(permuter.permuteUnique("aabc")); 
        // Expected output: All unique permutations like ["aabc", "aacb", "abac", ...]
    }
}
```
### Complexity Analysis
- **Time Complexity**: `O(n * n!)` for generating all unique permutations, as each permutation requires `O(n)` to build, and there are up to `n!` unique permutations.
- **Space Complexity**: `O(n!)` to store all unique permutations and `O(n)` for recursive call stack depth.

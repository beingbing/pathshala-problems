# permutations of a string - 1
## Problem
Given a string `s` with all distinct characters, print all possible permutations of the string.
## Solution
### Key Insights
1. **Permutation Definition**:
   - For a string of `n` distinct characters, there are `n!` unique permutations. A permutation involves rearranging the characters in every possible order.
2. **Backtracking Approach**:
   - Using backtracking, we can swap characters and recursively build each possible arrangement. Each time we swap two characters, we generate a new configuration of the string, allowing us to explore all permutations efficiently.
   - The backtracking algorithm is ideal here because it explores all possible arrangements by making choices (character swaps) and then backtracking to previous states to try other possibilities.
3. **Avoiding Duplicates**:
   - Since all characters in `s` are distinct, every arrangement will be unique, and we don’t need to worry about filtering duplicate permutations.
### Steps to Approach the Problem
1. **Recursive Backtracking (DFS)**:
   - Keep a running index to explore all positions 
   - Swap current character in the string with every other character (including itself), treating each position as a choice point.
   - For each choice (swap), recursively continue to the next position until the end of the string is reached.
   - Once a complete permutation is formed, store it in the result list.
3. **Backtrack Step**:
    - After adding a permutation, undo the last swap to restore the previous state. This allows exploration of other possible arrangements without interference.
### Pitfalls
- **Swapping Errors**: Ensure correct swapping and backtracking steps. It’s crucial to swap back after each recursive call to maintain the original order for further permutations.
### Code
```java
import java.util.ArrayList;
import java.util.List;

public class StringPermutations {

    private void generatePermutations(char[] chars, int index, List<String> result) {
        // Base case: if the index reaches the end, add current permutation to result
        if (index == chars.length) {
            result.add(new String(chars));
            return;
        }

        // Recursive case: fix the index 'index' and swap its character with all characters on its right, 
        for (int newCharIndex = index; newCharIndex < chars.length; newCharIndex++) {
            swap(chars, index, newCharIndex); // Swap current character with another character on its right
            generatePermutations(chars, index + 1, result); // Recurse for the next position
            swap(chars, index, newCharIndex); // Backtrack: undo the swap to restore original state
        }
    }

    private void swap(char[] chars, int i, int j) {
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
    }

    public List<String> permute(String s) {
        List<String> result = new ArrayList<>();
        generatePermutations(s.toCharArray(), 0, result);
        return result;
    }

    public static void main(String[] args) {
        StringPermutations permuter = new StringPermutations();
        System.out.println(permuter.permute("abc"));  // Expected output: [abc, acb, bac, bca, cab, cba]
    }
}
```
### Complexity Analysis
- **Time Complexity**: `O(n!)` for generating all permutations, where `n` is the length of the string.
- **Space Complexity**: `O(n)` for the recursion stack and auxiliary space used for swaps.

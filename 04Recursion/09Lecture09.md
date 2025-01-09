# Letter Combinations of a Phone Number
## Problem Statement
Given a string of digits ranging from 2 to 9, return all possible letter combinations that the numbers could represent, based on traditional phone keypad mapping. Here’s the mapping:

| Digit | Letters    |
|-------|------------|
| 2     | a, b, c    |
| 3     | d, e, f    |
| 4     | g, h, i    |
| 5     | j, k, l    |
| 6     | m, n, o    |
| 7     | p, q, r, s |
| 8     | t, u, v    |
| 9     | w, x, y, z |

## Solution Approach
1. **Recursive Backtracking**:
    - For each digit in the input string, select a character corresponding to it.
    - Recursively build all possible combinations by adding each character and moving to the next digit.
    - When the combination length matches the input length, add it to the results list.

2. **Recursive Helper Function**:
    - We create a helper function to perform the backtracking. Starting from an empty string, the function adds characters mapped to each digit.
    - It stops when the current combination’s length matches the input length.

## Code
```java
import java.util.ArrayList;
import java.util.List;

class Solution {
    private List<String> results = new ArrayList<>();
    private String[] mapping = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
    };

    public List<String> letterCombinations(String digits) {
        if (digits.isEmpty()) return results;
        backtrack("", digits, 0);
        return results;
    }

    private void backtrack(String combination, String digits, int index) {
        if (index == digits.length()) {
            results.add(combination);
            return;
        }

        String letters = mapping[digits.charAt(index) - '0'];
        for (char letter : letters.toCharArray()) {
            backtrack(combination + letter, digits, index + 1);
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.letterCombinations("47"));
    }
}
```

## Complexity Analysis
- **Time Complexity**: `O(3^n * 4^m)`, where `n` is the count of digits mapping to 3 letters (e.g., 2, 3, 4), and `m` is the count of digits mapping to 4 letters (e.g., 7, 9).
- **Space Complexity**: `O(3^n * 4^m)` for storing results in the `results` list.

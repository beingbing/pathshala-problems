# Balanced Parentheses
given n pairs of braces, print all balanced parentheses

## Solution
We’ll use recursion (backtracking) to ensure every generated combination is balanced. 

### Key Insight
Each valid parentheses combination has:
1. Exactly `n` opening and `n` closing parentheses.
2. At no point in the sequence should the number of closing parentheses exceed the number of opening parentheses, as it would create an imbalance.

### Approach
1. **Backtracking**:
    - Start with an empty string.
    - Use two counters: `open` (number of `(` used) and `close` (number of `)` used).
    - At each step, decide to add `(` or `)`, ensuring that:
        - We only add `(` if `open < n` (not exceeding `n` pairs).
        - We only add `)` if `close < open` (closing should not exceed opening).
    - If `open == close == n`, add the string to the result list since it's a complete and balanced combination.

2. **Edge Cases**:
- Ensure not to add a `)` when `close >= open` to avoid imbalance.
- Handle `n = 0` as a special case, returning an empty list.

### Code -
```java
import java.util.ArrayList;
import java.util.List;

public class BalancedParentheses {

    public static void main(String[] args) {
        int n = 3; // Example number of pairs
        List<String> result = generateParenthesis(n);
        System.out.println(result);
    }

    public static List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        generate(result, "", 0, 0, n);
        return result;
    }

    private static void generate(List<String> result, String current, int open, int close, int max) {
        // Base case: if the current combination is complete
        if (current.length() == max * 2) {
            result.add(current);
            return;
        }

        // Add '(' if open parentheses are less than max
        if (open < max)
            generate(result, current + "(", open + 1, close, max);

        // Add ')' if close parentheses are less than open
        if (close < open)
            generate(result, current + ")", open, close + 1, max);
    }
}
```

### Complexity Analysis
- **Time Complexity**: `O(2^n)`, as each recursive call can branch into two.
- **Space Complexity**: `O(2n)` for the call stack in the recursion and storage in the result list.

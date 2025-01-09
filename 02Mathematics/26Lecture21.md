# Introduction to Catalan Numbers

## Problem: Counting Balanced Parentheses Combinations
**Goal**: Given n, the number of pairs of parentheses, find the count of distinct combinations that form balanced parentheses expressions.

## Solution
The problem of finding the count of distinct balanced parentheses combinations with `n` pairs of parentheses is a classic example of **Catalan numbers**.

### Properties of Balanced Parentheses Combinations
For a valid, balanced parentheses combination:
1. **Prefix Validity**: At every position in the combination, the number of opening parentheses should be at least as many as the closing parentheses (count(opening braces) >= count(closing braces)).
2. **Equal Count**: The total number of opening parentheses should equal the total number of closing parentheses.

### Approach: Recursive Structure of Catalan Numbers
A valid balanced combination can be thought of in the form:
```
(inside) outside
```
This structure forms a recursive pattern:
1. **Select a Pair**: Choose a pair of parentheses, dividing the remaining n-1 pairs into two groups:
    - **Inside**: Placing `i` pairs inside.
    - **Outside**: Placing `n - 1 - i` pairs outside.

2. **Recurrence Relation**:
   By summing all valid combinations where `i` pairs are inside and `n - 1 - i` are outside, we get:
```
   f(n) = {i -> 0, n-1} ∑ (f(i)*f(n-i-1))
```
with base cases:
- `f(0) = 1`: One way to arrange zero pairs (the empty set).
- `f(1) = 1`: One way to arrange one pair `()`.

3. Alternatively, we can compute Catalan numbers as:
```
     C(n) = 1/(n+1) * 2nCn = (2n)!/((n+1)! * n!)
```

### Algorithm
**Dynamic Programming Approach**:
   - We use a DP array where `dp[i]` stores the count of valid parentheses combinations for `i` pairs.
   - Initialize `dp[0] = 1` because there's only one way to have 0 pairs of parentheses (the empty string).
   - For each `i`, we use the formula:
```
     dp[i] = {j -> 0, i-1} ∑ (dp[j] * dp[i-1-j])
```

### Code
The dynamic programming solution efficiently calculates Catalan numbers up to `n` by storing results in an array, avoiding redundant calculations.
```java
public class CatalanNumber {

    public static int catalan(int n) {
        // Array to store Catalan numbers up to n
        int[] dp = new int[n + 1];
        dp[0] = dp[1] = 1;

        // Fill dp array using the recursive relation
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }

    public static void main(String[] args) {
        int n = 3;
        System.out.println("Number of balanced parentheses combinations for " + n + " pairs: " + catalan(n));
    }
}
```

### Complexity Analysis
- **Time Complexity**: `O(n^2)` – Due to the nested loop, where each index is computed based on previous indices.
- **Space Complexity**: `O(n)` – For the dynamic programming array storing Catalan numbers up to `n`.

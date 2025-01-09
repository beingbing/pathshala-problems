# Using Pascal's Triangle for Calculating nCr

## Building Pascal's Triangle

**Pascal's Triangle** allows us to compute nCr values based on the property:
```
nCr = (n-1)Cr + (n-1)C(r-1)
```
Using this property, each entry in the triangle can be derived from the two entries directly above it. This approach avoids the factorial calculations that lead to extremely large numbers.

### Java Code for Pascal's Triangle

To build Pascal’s Triangle for any integer n, we can use a 2D array to store values, which keeps values manageable within Java's primitive limits.

```java
public class PascalTriangle {

    // 2D array to store values up to nCr for n <= 60
    private static long[][] pasc = new long[61][61];

    // Function to initialize Pascal's Triangle
    public static void buildPascalTriangle() {
        for (int i = 0; i <= 60; i++)
            for (int j = 0; j <= i; j++)
                if (j == 0 || j == i) pasc[i][j] = 1;  // Edge values
                else pasc[i][j] = pasc[i - 1][j] + pasc[i - 1][j - 1];
    }
}
```

## Problem 1: Selecting 5 People Excluding Specific Combinations
### Problem
Given 5 boys and 5 girls, count the total distinct ways to select a group of 5 people, excluding combinations with exactly 2 boys and 3 girls.
### Solution
1. **Total Combinations**: Selecting any 5 people from 10 is 10C5.
2. **Exclude Specific Group**: Subtract combinations with exactly 2 boys and 3 girls. We can compute this as: 10C5 - (5C2 * 5C3)

### Java Code
```java
public class CombinationExclusion {

    public static long distinctCombinations() {
        PascalTriangle.buildPascalTriangle();
        // Total combinations
        long totalComb = PascalTriangle.pasc[10][5];
        // Excluded combinations with 2 boys and 3 girls
        long excludedComb = PascalTriangle.pasc[5][2] * PascalTriangle.pasc[5][3];
        return totalComb - excludedComb;
    }

    public static void main(String[] args) {
        System.out.println("Distinct combinations excluding specific groups: " + distinctCombinations());
    }
}
```

## Problem 2: Choosing Groups with Specific Conditions
### Problem
Given m girls and n boys, select a group of t people containing no fewer than 4 boys and at least 1 girl, with constraints:
- 4 <= n <= 30
- 1 <= m <= 30
- 5 <= t <= m + n

### Solution
1. **Combination Constraints**: The group of t people must contain at least 4 boys and at least 1 girl.  
2. **Inclusion-Exclusion Principle**: Calculate (n + m)Ct then exclude combinations that violate the constraints:
   - Too few boys or no girls.

### Pascal’s Triangle-Based Calculation
Using Pascal's Triangle, we simplify nCr without involving large multiplications or divisions directly.

```java
public class SpecificCombinationConditions {

    public static long countCombinations(int n, int m, int t) {
        PascalTriangle.buildPascalTriangle();

        long totalCombinations = PascalTriangle.pasc[n + m][t];
        long invalidCombinations = 0;

        for (int i = 0; i <= 3 && t - i >= 0; i++) {
            if (t - i <= m && i <= n) {
                invalidCombinations += PascalTriangle.pasc[n][i] * PascalTriangle.pasc[m][t - i];
            }
        }

        return totalCombinations - invalidCombinations;
    }

    public static void main(String[] args) {
        int n = 1, m = 4, t = 5;
        System.out.println("Valid combinations: " + countCombinations(n, m, t));
    }
}
```

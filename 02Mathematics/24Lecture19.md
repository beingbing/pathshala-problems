# Understanding Combinations: nCr

This guide explains combinations, with examples that clarify how to count selections when the order of elements doesn’t matter.

## Problem 1: Choosing r Elements from n Elements
### Problem
From a set of n distinct items, we want to choose r items without regard to order. How many different combinations of r elements are possible?
### Solution
To choose r items from n, the **Rule of Product** initially gives:
```
n * (n - 1) * ... * (n - r + 1)
```
However, since the order of selection doesn’t matter, each combination includes **repeated permutations**. For example, if we choose two items A and B, both "AB" and "BA" represent the same combination.

To remove these duplicates, we divide by the number of ways to arrange r items:
```
r * (r - 1) * ... * 1 = r!
```
Thus, the formula for combinations (nCr) is:
```
nCr = n!/(r!*(n - r)!)
```

### Java Code

```java
public class Combination {

    // Function to calculate nCr
    public static int nCr(int n, int r) {
        return factorial(n) / (factorial(r) * factorial(n - r));
    }

    // Helper function to calculate factorial
    public static int factorial(int num) {
        int result = 1;
        for (int i = 2; i <= num; i++) {
            result *= i;
        }
        return result;
    }

    public static void main(String[] args) {
        int n = 5, r = 2;
        System.out.println("Number of ways to choose " + r + " from " + n + ": " + nCr(n, r));
    }
}
```

## Problem 2: Counting Bit Strings with Exactly k Ones
### Problem
For a bit string of size n, how many unique bit strings contain exactly k ones?
### Solution
To solve this, we select k positions from n positions and place a `1` in each of those positions. The rest will be filled with `0`s. Since the order does not matter, this selection is simply: nCk

### Java Code

```java
public class BitStringWithOnes {

    public static int countBitStringsWithKOnes(int n, int k) {
        return Combination.nCr(n, k);
    }

    public static void main(String[] args) {
        int n = 5, k = 2;
        System.out.println("Bit strings of size " + n + " with " + k + " ones: " + countBitStringsWithKOnes(n, k));
    }
}
```

## Problem 3: Choosing and Coloring Walls
### Problem
Given n walls, select any 3 walls and color them with Red, Green, and Blue. How many ways can this be done?
### Solution
1. **Choosing Walls**: Select any 3 walls out of n, which can be done in nC3 ways.
2. **Coloring**: Once we’ve selected 3 walls, there are 3! = 6 ways to assign colors R, G, and B to these walls.

Thus, the total number of ways is:
```
nC3 * 3!
```
### Java Code

```java
public class ColorWalls {

    public static int waysToColorWalls(int n) {
        return Combination.nCr(n, 3) * factorial(3);  // Multiply by 3! for color arrangements
    }

    public static void main(String[] args) {
        int n = 5;
        System.out.println("Ways to color 3 walls from " + n + " walls: " + waysToColorWalls(n));
    }

    // Helper method to calculate factorial
    private static int factorial(int num) {
        int result = 1;
        for (int i = 2; i <= num; i++) {
            result *= i;
        }
        return result;
    }
}
```

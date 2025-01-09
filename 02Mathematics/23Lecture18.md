# Permutations and Combinations

## Problem 1: Counting Configurations of a Bit String
### Problem
Given a bit string of size `n`, how many different configurations are possible?
### Solution
Each position in a bit string can either be a `0` or a `1`, providing **2 options** for each position. Using the **Rule of Product**, the total number of possible configurations for a string of size `n` is: 2^n

### Example
For `n = 3`:
- Positions: `_ _ _`
- Options for each position: `2 * 2 * 2 = 2^3 = 8`

### Java Code

```java
public class BitStringConfigurations {

    // Function to calculate the number of configurations for a bit string of size n
    public static int countConfigurations(int n) {
        return (int) Math.pow(2, n);  // Calculate 2^n
    }

    public static void main(String[] args) {
        int n = 3;
        System.out.println("Total configurations for bit string of size " + n + ": " + countConfigurations(n));
    }
}
```

## Problem 2: Counting Distinct Subsets of a Set
### Problem
For a given set containing unique elements, find the number of distinct subsets.
### Solution
Each element in a set can either be **included** or **excluded** from a subset, giving us **2 choices per element**. Thus, for a set with `n` elements, the total number of distinct subsets is: 2^n

### Example
For a set `S = {0, 1, 2}`, the number of distinct subsets is: 2^3 = 8

**Note**: The order of elements in subsets does not matter (permutations are not considered here).

### Java Code

```java
public class SubsetCount {

    // Function to calculate the number of distinct subsets for a set of size n
    public static int countSubsets(int n) {
        return (int) Math.pow(2, n);  // Calculate 2^n
    }

    public static void main(String[] args) {
        int n = 3;  // Size of the set
        System.out.println("Total distinct subsets for set of size " + n + ": " + countSubsets(n));
    }
}
```

## Problem 3: Counting Distinct Permutations of a Set
### Problem
For a set, find the total number of distinct permutations (arrangements in different orders).
### Solution
In a permutation, each position in an arrangement must be filled by an element from the set, with no option to skip any element. If the set has `n` unique elements, then:
1. The first position has **n choices**.
2. The second position has **(n-1) choices** (one element is used).
3. The third position has **(n-2) choices**, and so forth.

The total number of distinct permutations is:
n! = n * (n-1) * (n-2) * ... * 1

### Example
For a set `S = {0, 1, 2}`, the total number of distinct permutations is:
3! = 3 * 2 * 1 = 6

### Java Code

```java
public class PermutationCount {

    // Function to calculate factorial of a number (n!)
    public static int factorial(int n) {
        int result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    // Function to calculate the number of distinct permutations for a set of size n
    public static int countPermutations(int n) {
        return factorial(n);  // Calculate n!
    }

    public static void main(String[] args) {
        int n = 3;  // Size of the set
        System.out.println("Total distinct permutations for set of size " + n + ": " + countPermutations(n));
    }
}
```

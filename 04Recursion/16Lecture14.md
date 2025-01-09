# Fast Exponentiation

## Problem
Given two integers, `n` (the base) and `k` (the exponent), calculate `n^k` where `k >= 0`.

### Solution 1: Brute Force
1. **Approach**:
    - Multiply `n` by itself `k` times.
    - the problem can be represented as -
```
n^k = n * n^(k-1)
f(n, k) = n * f(n, k-1)
```
2. **Complexity**:
    - **Time Complexity**: `O(k)`
    - **Space Complexity**: `O(1)` (iterative), `O(k)` (recursive)

#### Code
**Iterative**
```java
public int bruteForcePowIterative(int n, int k) {
    int curVal = 1;
    for (int i = 0; i < k; i++) {
        curVal *= n;
    }
    return curVal;
}
```
**Recursive**
```java
public int bruteForcePowRecursive(int n, int k) {
    if (k == 0) return 1;
    return n * bruteForcePowRecursive(n, k - 1);
}
```

### Solution 2: Fast Exponentiation (Divide and Conquer)
1. **Approach**:
    - This method leverages the symmetry of the problem: both left and right results are identical, so we only need one recursive call to calculate `n^{k/2}`.
    - understand using the formula -
```
    n^k = n^{k/2} * n^{k/2}
    f(n, k) = f(n, k/2) * f(n, k/2)
```

2. **Edge Case**: If `k` is odd, multiply by `n` once more to handle the remaining power.
3. **Termination condition**: If `k = 0`, return 1 (any number to the power of 0 is 1).
4. **Complexity**:
    - **Time Complexity**: `O(log k)` due to halving the exponent each time.
    - **Space Complexity**: `O(log k)` for the recursive stack.

#### Code
```java
public int fastExponentiation(int n, int k) {
    if (k == 0) return 1; // Termination condition

    int val = fastExponentiation(n, k / 2); // Recursive call with halved power

    // Handle even and odd cases
    if (k % 2 == 0) return val * val;
    return n * val * val;
}

public static void main(String[] args) {
    int result = new Solution().fastExponentiation(2, 5);
    System.out.println("Result: " + result); // Output: 32
}
```
#### Note
Increasing number of subproblems by dividing k into more than 2 parts won't improve the complexity as the amount of work done on each step would also increase the same rate, which will make complexities higher (2 * logk).

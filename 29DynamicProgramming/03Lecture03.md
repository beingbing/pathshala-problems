# **Staircase Problem (Climbing Stairs)**  

## **Problem Statement**  
Given `n` stairs, starting from the 0th stair, we need to count the **distinct ways** to reach the `n`th stair using the following moves:  
- **1-step jump**
- **2-step jump**  

For example, to reach the **3rd stair**, the possible paths are:  
1. `1 → 1 → 1`
2. `2 → 1`
3. `1 → 2`  
Total ways = **3**  

---

## **1. Forming the Recurrence Relation**  

A **dynamic programming (DP) problem** is typically defined using an **optimal substructure**, meaning it can be broken down into smaller subproblems, which can be defined using recurrence relation. And a recurrence relation germinates from elements of choice.

There are two ways of interpreting the recurrence relation using elements of choice:

### **Total ways to go from i to n**

Here, to reach n from any stair `i`, we have two independent choices:
- Move **1 step** from `i`: `(i+1)`
- Move **2 steps** from `i`: `(i+2)`

Thus, the number of ways to reach `n` from `i` is the sum of ways to reach `(i+1)` and `(i+2)`:  
\[
f(i, n) = f(i+1, n) + f(i+2, n)
]
This is the **recurrence relation**.

#### **Base Cases**
- If `i > n`: **No valid path**, so return `0`.
- If `i == n`: Only **1 way** (stay at `n`).

### **Total ways to go from 0 to i**

Here, to reach any stair `i`, we have two choices:  
- Move **1 step** from `(i-1)`
- Move **2 steps** from `(i-2)`

Thus, the number of ways to reach `i` is the sum of ways to reach `(i-1)` and `(i-2)`:  
\[
f(i) = f(i-1) + f(i-2)
\]
This is the **recurrence relation**.  

#### **Base Cases**  
- If `i == 0`: Only **1 way** (stay at 0).  
- If `i < 0`: **No valid path**, so return `0`.  

---

## **2. Top-Down Approach (Recursion + Memoization)**  

### **Recursive Solution (Without Memoization)**
```java
int totalWays(int i, int n) {
    if (i > n) return 0;  // Invalid state
    if (i == n) return 1; // Only 1 way: stay at 0
    return totalWays(i+1, n) + totalWays(i+2, n);
}
```
```java
int totalWays(int i) {
    if (i < 0) return 0;  // Invalid state
    if (i == 0) return 1; // Only 1 way: stay at 0
    return totalWays(i-1) + totalWays(i-2);
}
```
🔴 **Time Complexity**: **O(2ⁿ)** (Exponential)  
🔴 **Space Complexity**: **O(n)** (Recursive Stack)  

This approach has **overlapping subproblems** (same values computed repeatedly), making it inefficient.

### **Optimized Top-Down (Memoization)**
By **storing computed results**, we avoid redundant calculations:  
```java
int[] ways;

int countWays(int n) {
    ways = new int[n + 1];
    Arrays.fill(ways, -1);
    return totalWays(0, n);
}

int totalWays(int i, int n) {
    if (i > n) return 0;
    if (i == n) return 1;
    if (ways[i] != -1) return ways[i];  // Check stored value
    ways[i] = totalWays(i+1, n) + totalWays(i+2, n);
    return ways[i];
}
```
```java
int[] ways;

int countWays(int n) {
    ways = new int[n + 1];
    Arrays.fill(ways, -1);
    return totalWays(n);
}

int totalWays(int i) {
    if (i < 0) return 0;
    if (i == 0) return 1;
    if (ways[i] != -1) return ways[i];  // Check stored value
    ways[i] = totalWays(i-1) + totalWays(i-2);
    return ways[i];
}
```
✅ **Time Complexity**: **O(n)** (Each state is computed once)  
✅ **Space Complexity**: **O(n)** (Memoization storage)  

---

## **3. Bottom-Up Approach (Tabulation)**
Instead of recursion, we can build the solution **iteratively**:  

### **Iterative DP (O(n) Space)**
```java
int countWays(int n) {
    int[] dp = new int[n+1];
    Arrays.fill(dp, -1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}
```
✅ **Time Complexity**: **O(n)**  
✅ **Space Complexity**: **O(n)**  

---

### **Optimized Iterative DP (O(1) Space)**
Since we only need the last **two** values, we can eliminate extra space:  

```java
int countWays(int n) {
    if (n == 0) return 1;
    int f = 1, s = 1;
    for (int i = 2; i <= n; i++) {
        int cur = f + s;
        f = s;
        s = cur;
    }
    return s;
}
```
✅ **Time Complexity**: **O(n)**  
✅ **Space Complexity**: **O(1)**  

---

## **4. Summary: Comparing Approaches**
| Approach        | Time Complexity | Space Complexity |
|----------------|---------------|----------------|
| **Recursive (Brute Force)**  | O(2ⁿ) | O(n) (Call Stack) |
| **Top-Down (Memoization)**   | O(n)  | O(n) |
| **Bottom-Up (Tabulation)**   | O(n)  | O(n) |
| **Optimized Bottom-Up**      | O(n)  | O(1) |

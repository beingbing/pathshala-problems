### **Top-Down vs Bottom-Up in Dynamic Programming**  

Dynamic Programming (DP) is a smarter way of solving **recursion and backtracking** problems by eliminating redundant computations. Let's explore two approaches:  

---

## **1. Why Use DP?**  
Consider the naive recursive Fibonacci function:  

```cpp
int fib(int n) {
    if (n < 2) return n;
    return fib(n-1) + fib(n-2);
}
```
This **top-down** approach has **overlapping subproblems**, causing **exponential** time complexity **O(2ⁿ)**. As `n` increases, redundant calls slow down execution drastically.  

To optimize, we can **store computed results (memoization)**:  

```cpp
int fib(int n) {
    if (n < 2) return n;            // Base case
    if (ans[n] != -1) return ans[n]; // Memoization check
    ans[n] = fib(n-1) + fib(n-2);    // Compute and store
    return ans[n];
}
```
This method, known as **memoization (Top-Down DP)**, reduces the time complexity to **O(n)**.  

---

## **2. Key Concept: State Representation**  
- **State variables** define a unique problem instance.  
- In Fibonacci, `n` is the state variable.  
- The `ans[]` array is not a state but a storage structure.  

### **Space Complexity in Memoization:**  
Total extra space = **recursion stack + memoization storage** ≈ **O(n) + O(n) → O(n)**  

---

## **3. Bottom-Up Approach (Tabulation)**  
Instead of recursion, we can **iteratively** build the solution from smaller subproblems:  

```cpp
int fib(int n) {
    if (n == 0) return 0;
    int f = 0, s = 1;
    for (int i = 2; i <= n; i++) {
        int cur = f + s;
        f = s;
        s = cur;
    }
    return s;
}
```
This method:  
- Uses **iteration instead of recursion**  
- Avoids extra **O(n)** space for recursion stack  
- Reduces **space complexity to O(1)**  

---

## **4. Comparing Top-Down vs Bottom-Up**  

| Approach         | Time Complexity | Space Complexity |
|-----------------|---------------|----------------|
| **Top-Down (Memoization)** | O(n) | O(n) (Recursion + Storage) |
| **Bottom-Up (Tabulation)** | O(n) | O(1) |

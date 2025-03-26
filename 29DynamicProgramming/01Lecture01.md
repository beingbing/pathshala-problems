### **What is Dynamic Programming (DP)?**

**Prerequisites:**
- Recursion
- Backtracking
- Greedy Algorithms

### **1. Understanding DP**
Dynamic Programming (DP) is an **optimized** version of **recursion and backtracking**. When a **greedy** approach fails to find the optimal solution, we explore all possible solutions using recursion. However, **plain recursion** often leads to redundant calculations. DP **eliminates redundancy** by storing previously computed results, making it more efficient in terms of **time and space**.

### **2. Key Concept: Optimal Substructure**
At the core of DP lies the **recurrence relation**, which expresses a **larger problem** in terms of **smaller subproblems**. This concept is known as **optimal substructure** in DP.

### **3. Two Approaches to DP**

#### **(a) Top-Down (Memoization)**
- Uses **recursion** to break the problem into smaller subproblems.
- Stores results of subproblems to avoid redundant computation.

#### **(b) Bottom-Up (Tabulation)**
- Uses **loops** to build solutions from the smallest subproblems to the final solution.
- More **space-efficient** in some cases, as only necessary values are stored instead of the entire recursion tree.

### **4. Choosing the Right Approach**
- **Top-down (recursion + memoization)** is easier to understand but may have higher space usage due to recursion stack.
- **Bottom-up (tabulation)** is often more space-efficient, especially when subproblem dependencies are minimal.

By applying DP, we **avoid recomputation**, improving performance **significantly** over brute-force recursion.
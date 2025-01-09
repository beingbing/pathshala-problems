# Understanding the Basics of Recursion
Recursion is a programming technique where a function calls itself with modified arguments, often to break down a complex problem into simpler subproblems. This process of a function calling itself is central to recursive problem-solving.

## Key Components of Recursion
1. **Recursive Call**: The part where the function calls itself to tackle a smaller portion of the original problem.
2. **Termination (Base) Condition**: A condition that stops the recursive calls, preventing an infinite loop. Every recursive function must have a base condition.

## Recurrence Relation
A **recurrence relation** is a mathematical expression that defines each term of a sequence as a function of its preceding terms, helping to solve larger problems in terms of smaller ones.

For example, factorial calculations can be defined using a recurrence relation:
```
         n! = (n-1)! * n
=>  fact(n) = fact(n-1) * n     for all n > 0
```
This relation tells us that to find `n!`, we can calculate `(n-1)!` and multiply it by `n`. This recursive breakdown continues until reaching `0!` = 1, the termination condition.

### Code
```java
int factorial(int n) {
    if (n == 0) return 1;  // Base condition
    return n * factorial(n - 1);  // Recursive call with recurrence relation
}
```
**Explanation**:
- The **base condition** (`n == 0`) stops the recursion.
- The **recursive call** (`factorial(n - 1)`) reduces the problem size by 1 each time.
- The recursion unfolds from the base condition upwards, calculating each factorial value step-by-step.

## Characteristics of a Recurrence Relation
A recurrence relation is specific to certain inputs or constraints. It may not apply universally to all values, as it generally depends on the problem's structure. For example, the factorial recurrence relation only applies to non-negative integers.

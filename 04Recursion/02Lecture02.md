# Single Branch Recursion Explained
Single-branch recursion refers to recursion where a function has only one recursive call in its body. This makes the control flow straightforward, resembling a linear sequence with depth-first traversal.

Let’s look at an example of calculating the factorial of a number using single-branch recursion.

## Example: Recursive Factorial Calculation
```java
int factorial(int n) {
    if (n == 0) return 1;  // Termination condition
    return n * factorial(n - 1);  // Recursive call with recurrence relation
}

public static void main(String[] args) {
    int result = factorial(5);  // Initialization
    System.out.println(result);  // Output: 120
}
```
### Explanation: Three pillars of recursion
1. **Initialization**: The recursion is initiated by calling `factorial(5)`.
2. **Termination Condition**: The recursion halts when `n == 0`, returning 1.
3. **Recurrence Relation**: Each recursive call computes `n * factorial(n-1)` until `n` reaches 0.

## Flow of Execution and Control
1. **Depth-First Traversal**: The recursive calls progress from top to bottom, with each `factorial(n)` call waiting for `factorial(n-1)` to return.
2. **Call Stack**: Each recursive call is pushed onto the stack. Since the last call is returned first, this follows the **Last-In-First-Out (LIFO)** principle.
3. **Bottom-to-Top Return**: Once the termination condition is met, the function values start returning from the deepest call back up the stack until reaching the initial call.

**Diagram of Call Flow:**
```plaintext
main
 |         ^   returns 1 * 1 * 2 * 3 * 4 * 5 = 120
factorial(5)
 |         ^   returns 1 * 1 * 2 * 3 * 4
factorial(4)
 |         ^   returns 1 * 1 * 2 * 3
factorial(3)
 |         ^   returns 1 * 1 * 2
factorial(2)
 |         ^   returns 1 * 1
factorial(1)
 |         ^   returns 1
factorial(0)  // base case
```

## Time Complexity and Space Complexity
- **Time Complexity**: `O(n)` since the function `factorial(n)` calls itself `n` times.
- **Space Complexity**: `O(n)` as each call is stored on the stack until resolved.

## Three Pillars of Recursion
1. **Initialization**: The starting call or input that initiates the recursive sequence.
2. **Recurrence Relation**: The relationship that breaks down the problem, here `n * factorial(n-1)`.
3. **Termination Condition**: A condition that stops the recursion, preventing infinite looping (e.g., `n == 0` in this case).

## Key Points
- Recursion internally uses the call stack, following a LIFO principle.
- Single-branch recursion is linear, moving deeply down to the base case before resolving each call.

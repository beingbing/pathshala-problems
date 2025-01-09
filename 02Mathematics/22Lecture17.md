# Basics of Combinatorics

## 1. Rule of Product (Multiplication Principle)

**Concept**:  
If a task can be broken down into two or more independent steps, where each step has multiple distinct options, the total number of ways to complete the task is the product of the ways for each step.

### Problem Example
Consider three cities, **A**, **B**, and **C**:
- City **A** connects to city **B** via 3 distinct roads: P, Q, and R.
- City **B** connects to city **C** via 2 distinct roads: P' and Q'.

The question is: **In how many ways can a person travel from city A to city C?**

### Solution
1. From **A** to **B**, there are 3 independent options: P, Q, and R.
2. From **B** to **C**, there are 2 independent options: P' and Q'.

Since each choice between A and B can pair with each choice between B and C, the **total number of ways** is: 3 * 2 = 6. Thus, there are 6 unique ways to travel from A to C.

### General Rule
If a task **A** can be completed by performing two independent actions, **A'** and **A''**, where:
- **A'** has `n` possible ways
- **A''** has `m` possible ways

Then, the number of ways to complete **A** is: Total ways = n * m

### Java Code Example
Here's a Java method to calculate the total number of ways to complete a task given the number of options for each step:

```java
public class Combinatorics {

    // Function to calculate the total ways given options in each step
    public static int calculateWays(int[] options) {
        int totalWays = 1;
        for (int option : options) {
            totalWays *= option;  // Apply the rule of product
        }
        return totalWays;
    }

    public static void main(String[] args) {
        // Number of ways for each part of the journey
        int[] roads = {3, 2};  // A to B has 3 roads, B to C has 2 roads
        System.out.println("Total ways to travel from A to C: " + calculateWays(roads));
    }
}
```

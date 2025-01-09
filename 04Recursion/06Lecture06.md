# Recursive Printing from 1 to n
To print numbers recursively from 1 to `n`, you’ll need to consider:
1. **Function Design**
    - Decide on the function name, parameters, and return type.
    - Plan how each recursive call will interact with the stack.
2. **Termination Condition**
    - Specify when the recursion should stop.
3. **Recurrence Relation**
    - Define how each function call should progress toward the termination condition.
    - Decide on the responsibilities of each delegated function call.
4. **Initialization**
    - Set up the initial call in `main` and pass any required arguments.

## Approach 1: Print from 1 to n
This approach prints numbers in ascending order from 1 to `n`. It follows the recursive stack until reaching 1, then prints values in the stack’s unwind phase.
```java
public class RecursivePrint {

    // Prints from 1 to n
    public static void printAscending(int n) {
        if (n < 1) return;
        printAscending(n - 1);
        System.out.println(n);
    }

    public static void main(String[] args) {
        int n = 5;
        printAscending(n);
    }
}
```

**Output**:
```
1
2
3
4
5
```

## Approach 2: Print from n to 1
This approach prints numbers in descending order, from `n` down to 1, by printing first before making the recursive call.

```java
public class RecursivePrint {

    // Prints from n to 1
    public static void printDescending(int n) {
        if (n < 1) return;
        System.out.println(n);
        printDescending(n - 1);
    }

    public static void main(String[] args) {
        int n = 5;
        printDescending(n);
    }
}
```

**Output**:
```
5
4
3
2
1
```

## Approach 3: Print from 1 to n Using an Incremental Parameter
Here, we pass an additional parameter to track the current number, printing from 1 to `n` directly.
```java
public class RecursivePrint {

    // Prints from 1 to n using additional parameter
    public static void printAscendingFromX(int x, int n) {
        if (x > n) return;
        System.out.println(x);
        printAscendingFromX(x + 1, n);
    }

    public static void main(String[] args) {
        int n = 5;
        printAscendingFromX(1, n);
    }
}
```

**Output**:
```
1
2
3
4
5
```

## Approach 4: Print from n to 1 Using an Incremental Parameter
This method prints from `n` down to 1 by first going deeper in the call stack and printing during the unwind phase.
```java
public class RecursivePrint {

    // Prints from n to 1 using additional parameter
    public static void printDescendingFromX(int x, int n) {
        if (x > n) return;
        printDescendingFromX(x + 1, n);
        System.out.println(x);
    }

    public static void main(String[] args) {
        int n = 5;
        printDescendingFromX(1, n);
    }
}
```

**Output**:
```
5
4
3
2
1
```

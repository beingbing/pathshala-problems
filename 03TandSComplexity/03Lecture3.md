# Analyzing Code Time Complexities
We’ll examine some code snippets, each demonstrating different runtime complexities, through analysis and recurrence relations.

## Q1. Nested Linear Iterations (O(n²))
In the following code, each iteration of `i` requires a linear pass through `j`, resulting in a quadratic time complexity.

```java
void func(int n) {
    int i = 0, j = 0;
    for (; i < n && j < n; ) {
        if (i == j) {
            i++;
            j = 0;
        } else {
            j++;
        }
    }
}
```

| `i`   | `j`                 | Operations |
|-------|---------------------|------------|
| 0     | 0                   | 1          |
| 1     | 0 1                 | 2          |
| 2     | 0 1 2               | 3          |
| 3     | 0 1 2 3             | 4          |
| ...   | ...                 | ...        |
| (n-1) | 0 1 2 3 4 ... (n-1) | n          |

Time Complexity = Total operations = 1 + 2 + 3 + ... + n = n(n+1)/2 = O(n^2).

## Q2. Logarithmic Decrement (O(log n))
This snippet halves `i` in each iteration, leading to a logarithmic time complexity, `O(log n)`.

```java
void func(int n) {
    int a = 0;
    int i = n;
    while (i > 0) {
        a += i;
        i /= 2;
    }
}
```

### iterative analysis
After each step:
- i = n, n/2, n/4, ..., 1
- assuming loop runs x times
- after x iterations n/2^x = 1 = log_2 n = x
- Thus, the loop iterates log_2(n) times.
- time complexity will be O(log n)

### Recurrence Relation Approach
 T(n) = T(n/2) + O(1)
Solving this gives T(n) = O(log n)

## Q3. Logarithmic Inner Loop (O(n log n))
Here, `j` grows exponentially within each `i` iteration, resulting in O(log i) inner operations for each `i` from `1` to `n`.

```java
void func(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j *= 2) {
            System.out.println(i + " " + j);
        }
    }
}
```

| `i` | `j`             | Operations  |
|-----|-----------------|-------------|
| 1   | 1               | 1 (log_2 1) |
| 2   | 1 2             | 2 (log_2 2) |
| 3   | 1 2             | 2 (log_2 3) |
| 4   | 1 2 4           | 3 (log_2 4) |
| 5   | 1 2 4           | 3 (log_2 5) |
| 6   | 1 2 4           | 3 (log_2 6) |
| 7   | 1 2 4           | 3 (log_2 7) |
| 8   | 1 2 4 8         | 4 (log_2 8) |
| ... | ...             | ...         |
| n   | 1 2 4 8 ... 2^x | x (log_2 n) |

so, total number of operations = log1 + log2 + log3 + .... + logn = log (1*2*3...n) = log(!n)
and !n ~= (n^n),
so, Total operations ≈ O(n log n).
Hence, time taken = O(nlogn)

## Q4. Nested Halving and Linear Inner Loop (O(n))
Each iteration of the outer loop halves `i`, while the inner loop performs `i` operations. This results in linear time complexity.
```java
void func(int n) {
    for (int i = n; i > 0; i /= 2) {
        for (int j = 0; j < i; j++) {
            System.out.print(" ");
        }
    }
}
```

    i:  n           n/2             n/4             n/8             ....    2       1

    j:  1 2 ... n   1 2 ... n/2     1 2 ... n/4     1 2 4 ... n/8   ....    1 2     1

no of:  n           n/2             n/4             n/8                     2       1
operations

so, total number of operations = n + n/2 + n/4 + n/8 + ... + 3 + 2 + 1

=> T(n) = n (1 + 1/2 + 1/4 + 1/8 + ...)

formula for sum of infinite GP is Sn = a / (1-r), here, a is first term and r = common difference

so, T(n) = n * (1/(1/2)) = 2*n

=> T(n) = O(n)



Note:
1. sum of reciprocal of primes numbers till n is loglogn
2. sum of reciprocal of all natural numbers till n is logn

Operations:
- Total ≈ \( n + \frac{n}{2} + \frac{n}{4} + \dots + 1 \)

Using the sum formula for a geometric progression, this simplifies to \( O(n) \).

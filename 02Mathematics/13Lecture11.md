### counting divisors faster

Problem: Given q queries each gives a number N, give count of the divisors of N.

Approach 1: divisors come in pairs. If d is a divisor of N, then N/d is also a divisor. It is good if you need to find divisor for just a single number. The time complexity is O(sqrt(n)) * q
```java
    public static int countDivisors(int N) {
        int count = 0;

        // Iterate from 1 to sqrt(N)
        for (int i = 1; i * i <= N; i++)
            if (N % i == 0) // i is a divisor, and N/i is also a divisor
                if (i == N / i) count += 1; // If both divisors are the same, count only once
                else count += 2; // Otherwise, count both divisors

        return count;
    }
```

Approach 2:
N can be represented in terms of it's prime factors as -
        N = p^l * q^m * r^n * .....

its divisor will be -

        d = p^i * q*j * r*k * .....
where,
        0 <= i <= l
        0 <= j <= m
        0 <= k <= n ....

so, count of total divisors will be -
    (l+1)*(m+1)*(n+1)* .....

While reducing numbers using SPF we can track how many times a divisor is invoked, and by using that number we can get values of l, m, n, etc.

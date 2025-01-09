# smallest good base
## Background Knowledge
before discussing the main problem, lets gain some background knowledge
by default all numbers are written in base 10, hence digits considered are from 0 till 9, not more than 10.
so, if we try to represent a digit in base k, the digits will range from 0 till k-1.

## Problem
a base is defined as a good base iff all the digit representation in that base for a number is 1. Find smallest good base k for a number n.
A base `k` is called a good base for a number `n` if `n` can be represented in base `k` using only the digit 1. The goal is to find the smallest good base `k` for a given `n`.
constraints:
- k >= 2
- n belongs to the range `[3, 10^18]`

### Solution
### Key Observations
1. there can be multiple good bases for a number
2. every number has 1 as the smallest good base, but we won't consider it
3. every number n has n-1 as the largest good base
4. Conclusions: domain of smallest good base will be `[2, n-1]` so, we can Binary Search on this domain and look for our answer.

#### Definition of a good base:
If a number `n` can be represented as `111...1` in base `k` with `m+1` ones, it satisfies the equation:
```
n = k^m + k^{m-1} + ... + k + 1
```
This sum is a geometric series, and for base `k`, it evaluates to:
```
n = (k^{m+1} - 1)/(k - 1)
```
Here, `k` and `m` are what we need to find. Any of the above two representations can be used to evaluate a randomly given base for being a good base. We aim to find the smallest possible `k` such that this equation holds.

Here, we have got two unknowns, and our aim is to apply binary search on answer, hence to be able to apply Binary Search on `k`, we need to define a domain in which we can start searching for `k`. But before that, we need to gather upper and lower bounds of `m` as well.

To understand what `m` represents, suppose a number `n` has three good bases `a`, `b` and `c` such that -
```
n = 1 * a^0 + 1 * a^1 + 1 * a^2
n = 1 * b^0 + 1 * b^1 + 1 * b^2 + 1 * b^3
n = 1 * c^0 + 1 * c^1 + 1 * c^2 + 1 * c^3 + 1 * c^4 + 1 * c^5
```
Here, we can conclude, `a > b > c` with highest power respectively as `2 < 3 < 5`. Thus, in this case, `m` will range from `[2, 5]` 

#### Range for `m`:
Since `n` can be very large (up to `10^{18}`), we need to set a practical upper limit for `m`. For a given `n`, taking `k` as `2` (smallest possible value), `m` can have a maximum possible value of `log_2(n)`. Hence, The maximum possible `m` for given constraints is around `log_2(10^{18})` which is approximately `60` (taking upper bound). Similarly, the minimum possible `m` can be `log_2{3}` which is approximately `1` (taking lower bound).

Concluding that, according to constraints, for a given `n`, value of `m` can range in `[1, 60]`.

As, `m` has very small range, and bigger the `m`, smaller will be the base, so for a given `n` we can iterate from largest value to smallest and do -
```java
import java.math.BigInteger;
import java.util.Scanner;

public class SmallestGoodBase {
    
    public static String findSmallestGoodBase(String n) {
        BigInteger num = new BigInteger(n);
        
        // Try each possible m (number of 1's in the representation - 1)
        for (int m = 60; m >= 1; m--) {
            // Binary search for k, which satisfies n = k^m + k^(m-1) + ... + 1
            BigInteger low = BigInteger.valueOf(2);
            BigInteger high = num;
            
            while (low.compareTo(high) <= 0) {
                BigInteger mid = low.add(high).divide(BigInteger.TWO);
                
                // Compute: (k^(m+1) - 1) / (k - 1)
                BigInteger left = mid.pow(m + 1).subtract(BigInteger.ONE);
                BigInteger right = mid.subtract(BigInteger.ONE);
                
                BigInteger result = left.divide(right);
                
                // Check if we found the correct base
                if (result.equals(num)) {
                    return mid.toString();
                } else if (result.compareTo(num) < 0) {
                    low = mid.add(BigInteger.ONE);
                } else {
                    high = mid.subtract(BigInteger.ONE);
                }
            }
        }
        
        // If no valid base found, the only base is n-1 (for n to be represented as "11" in base n-1)
        return num.subtract(BigInteger.ONE).toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt(); // Number of test cases
        scanner.nextLine(); // Consume newline
        
        for (int i = 0; i < t; i++) {
            String n = scanner.nextLine();
            System.out.println(findSmallestGoodBase(n));
        }
        
        scanner.close();
    }
}
```
with TC = `O(60*logn)`

But, we can not practically store such a big number in a normal variable. Obviously, we can use `BigInteger`, but there got to be a better way to handling or avoiding such a big calculation.

The integer overflow conditions are occurring when we are generating and storing too big a number even when it is not needed. To stop the overflow condition instead of doing -
```
x = x * m;
sum += x
```
for an extensively large `x`, where, Point of overflow will be `x = x * m` due to large `x * m`, so if, `n - sum < x * m` then our multiplication is unnecessary, hence, check whether it is even required by evaluating -
```
(n - sum) / x < m
```

#### Code
```java
public class SmallestGoodBase {
    public String smallestGoodBase(String str) {
        long n = Long.parseLong(str);

        for (int m = 60; m >= 1; m--) {
            long low = 2, high = n - 1;

            while (low <= high) {
                long k = low + (high - low) / 2;
                long sum = 0, currentTerm = 1;
                boolean overflow = false;

                for (int i = 0; i <= m; i++) {
                    sum += currentTerm;
                    if (sum > n) break;
                    if (i < m && (n - sum) / currentTerm < k) {
                        overflow = true;
                        break;
                    }
                    if (i < m) currentTerm *= k;
                }

                if (sum > n || overflow) {
                    high = k - 1;
                } else if (sum < n) {
                    low = k + 1;
                } else {
                    return Long.toString(k);
                }
            }
        }
        return "2";
    }
}
```

#### Explanation of Code
1. Outer Loop on `m`: Iterates over possible values of `m` from 60 down to 1, trying to find the smallest `k` for each `m`.
2. Binary Search on `k`: Uses binary search within `[2, n-1]` to find `k` such that the sum of the geometric series equals `n`.
3. Overflow Handling: The inner loop calculates terms in the series one by one, using the overflow flag to break early if overflow is likely.
4. Return Smallest Good Base: If a valid `k` is found, it’s returned immediately. If no good base is found in the range, return "1" as a fallback.

#### Complexity Analysis
- **Time Complexity:** `O(60*((log^2)(n)))`. The outer loop for `m` is constant (bounded by 60), and binary search for `k` takes `O(logn)` for each `m`.
- **Space Complexity:** `O(1)`. Only basic variables are used; no extra space is needed beyond constant storage.

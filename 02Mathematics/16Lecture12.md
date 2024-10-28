# Segmented Sieve Algorithm

## Problem
The classic **Sieve of Eratosthenes** has high memory usage with a space complexity of **O(n)**, making it impractical for very large values like n = 10^10. We need an efficient way to find prime numbers in a large range.

## New Problem Formulation
Given two large numbers `l` and `r` with (l, r approx 10^10) and (r - l approx 500)), we need to **print all prime numbers in the range `[l, r]`**.

Since the range `[l, r]` is relatively small, we can solve this with a **Segmented Sieve Algorithm** that:
1. Finds all primes up to ( sqrt{r} ) using a simple sieve.
2. Uses these primes to mark non-prime numbers in `[l, r]`.

## Approach:
### Key Insight
To identify primes within `[l, r]`, we only need primes up to (sqrt{r}). This is because:
1. Any composite in `[l, r]` will have a factor smaller than or equal to (sqrt{r}).
2. We can use the primes up to (sqrt{r}) to mark multiples within `[l, r]` as non-prime.

### Steps for the Segmented Sieve Algorithm
1. **Sieve up to (sqrt{r}):**
    - Use a basic Sieve of Eratosthenes to find all primes up to (sqrt{r}). These primes are used to strike off composites in `[l, r]`.

2. **Initialize Range Array `[l, r]`:**
    - Create a boolean array for `[l, r]` of size `(r - l + 1)` and initially set all entries to `true`, assuming all numbers in this range are prime.

3. **Mark Non-Primes in `[l, r]`:**
    - For each prime `p` up to (sqrt{r}), find the first multiple of `p` within `[l, r]`:
        - Calculate the first multiple as `p * ceil(l / p)`.
        - Mark all multiples of `p` in `[l, r]` as `false` (non-prime).

4. **Extract Primes from Array:**
    - Remaining `true` values in the range array indicate prime numbers. Convert each index back to the corresponding number in `[l, r]` by `index + l`.

---

### Code Implementation

```cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Simple Sieve to generate primes up to sqrt(r)
vector<int> generatePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return primes;
}

// Segmented Sieve to find primes in the range [l, r]
vector<int> segmentedSieve(long long l, long long r) {
    int limit = sqrt(r);
    vector<int> primes = generatePrimes(limit);

    // Initialize all entries in range [l, r] as true (assuming all are prime)
    vector<bool> isPrime(r - l + 1, true);

    for (int p : primes) {
        // Find the starting point for marking multiples of p in the range [l, r]
        long long start = max(p * p, l + (p - l % p) % p);
        
        // Mark all multiples of p in the range [l, r] as non-prime
        for (long long j = start; j <= r; j += p) {
            isPrime[j - l] = false;
        }
    }

    // Collect all primes in the range [l, r]
    vector<int> result;
    for (long long i = l; i <= r; i++) {
        if (isPrime[i - l] && i > 1) result.push_back(i); // i > 1 to exclude 1 if in range
    }

    return result;
}

int main() {
    long long l, r;
    cin >> l >> r;  // Input range [l, r]

    vector<int> primesInRange = segmentedSieve(l, r);
    for (int prime : primesInRange) {
        cout << prime << " ";
    }

    return 0;
}
```

### Explanation of Key Steps in Code:
1. **Simple Sieve for Primes up to \( \sqrt{r} \)**:
    - `generatePrimes(int limit)`: A standard sieve to find all primes up to `sqrt(r)`.

2. **Segmented Sieve on Range `[l, r]`**:
    - `segmentedSieve(long long l, long long r)`: Marks non-primes within `[l, r]` based on primes from the simple sieve.
    - Each `p`’s first multiple within `[l, r]` is calculated as `start = max(p * p, l + (p - l % p) % p)` to skip marking numbers below `l`.

3. **Extracting Primes in Range `[l, r]`**:
    - Only entries that remain `true` in the array correspond to prime numbers in `[l, r]`.

---

### Complexity Analysis
- **Time Complexity:**
    - Simple sieve up to \( \sqrt{r} \): **O(sqrt(r) * log(log(sqrt(r))))**.
    - Marking non-primes in `[l, r]` using these primes: **O((r - l) * log(log(sqrt(r))))**.
    - Since `(r - l)` is small compared to \( \sqrt{r} \), the effective time complexity is **O(sqrt(r) * log(log(sqrt(r))))**.

- **Space Complexity:**
    - The array for the range `[l, r]` has a size of `O(r - l + 1)`, which is small and efficient to handle.


**Card 2**  
**Question:** What is the segmented sieve used for in range `[l, r]`?  
**Answer:** The segmented sieve efficiently finds primes in a range `[l, r]` by marking non-primes using primes up to sqrt(r).

---

**Card 3**  
**Question:** What are the two main steps in the segmented sieve algorithm?  
**Answer:** 1. Find all primes up to sqrt(r) using a basic sieve. 2. Use these primes to mark non-primes within `[l, r]`.

---

**Card 4**  
**Question:** How do you determine the first multiple of a prime `p` in the range `[l, r]` for the segmented sieve?  
**Answer:** Calculate it as `p * ceil(l / p)`, or equivalently `max(p * p, l + (p - l % p) % p)`.

---

**Card 5**  
**Question:** What is the time complexity of the segmented sieve algorithm?  
**Answer:** The time complexity is **O(sqrt(r) * log(log(sqrt(r))))** due to the initial sieve up to sqrt(r) and marking within `[l, r]`.
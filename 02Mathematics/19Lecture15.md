# Counting Pairs Divisible by a Given Number

**Problem:** Given an array `a[]` of size `n` containing non-negative integers, find the total number of distinct pairs `(i, j)` such that (a[i] + a[j]) is divisible by a given integer k. Pairs where `i == j` are not allowed, and pairs `(i, j)` and `(j, i)` should be considered the same.

## Approach 1: Brute Force
The simplest way to solve this is to check every possible pair in the array to see if their sum is divisible by `k`.

### Algorithm:
1. Initialize a counter, `count`, to zero.
2. Use two nested loops to iterate over every pair `(i, j)` where i < j.
3. Check if a[i] + a[j]) % k == 0. If true, increment the counter.

### Code:
```java
public static int countPairsBruteForce(int[] arr, int k) {
    int count = 0;
    int n = arr.length;
    
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if ((arr[i] + arr[j]) % k == 0)
                count++;
    
    return count;
}
```
**Time Complexity:** O(n^2)
**Space Complexity:** O(1)

## Approach 2: Using Remainder (modulo) Buckets
Since we’re interested in sums divisible by `k`, we can optimize using **modular property `remainder of sums = sum of remainder % m`** by distributing elements into **remainder buckets** [0, 1, 2, 3,...., k-3, k-2, k-1] and then calculate their contributions.

### Key Insight:
- For any two elements a[i] and a[j], (a[i] + a[j]) % k = ((a[i] % k) + (a[j] % k)) % k = 0 resolves LHS into range (0, 2k-2), which equate to 0 if their remainders sum is either `0` or `k`.
- This gives three cases to consider:
    1. **Both remainders are zero:** Any two elements with remainder `0` can form valid pairs.
    2. **Remainders are complementary:** If one element has remainder `r`, the other should have remainder `k - r`.
    3. **Middle bucket (if `k` is even):** If `k` is even, pairs within the bucket `k/2` also need special handling, as any two elements in this bucket form a valid pair.

### Algorithm:
1. Create an array `count[]` of size `k` to store the frequency of each remainder.
2. Populate `count[]` by iterating through the array and counting the remainders of each element modulo `k`.
3. For each bucket, compute valid pairs:
    - Pairs within the `0` remainder bucket can be formed as combinations nC2 of elements (choose two from `count[0]`).
    - For each remainder `i` from `1` to `k/2`, calculate pairs with remainder `k - i` using rule of product
    - If `k` is even, handle the middle bucket `k/2` separately using nC2 as well.

### Code:
```java
import java.util.Arrays;

public static int countPairsEfficient(int[] arr, int k) {
    int n = arr.length;
    int[] count = new int[k];
    Arrays.fill(count, 0);
    
    // Populate remainder frequency array
    for (int num : arr) count[num % k]++;
    
    int pairs = 0;
    
    // Case 1: Pairs within remainder 0 bucket
    pairs += (count[0] * (count[0] - 1)) / 2;
    
    // Case 2: Complementary remainder pairs
    for (int i = 1; i <= k / 2; i++)
        if (i != k - i)
            pairs += count[i] * count[k - i];
    
    // Case 3: Middle bucket (if k is even)
    if (k % 2 == 0)
        pairs += (count[k / 2] * (count[k / 2] - 1)) / 2;
    
    return pairs;
}
```
**Time Complexity:** O(n + k)
**Space Complexity:** O(k)

### Note:
Use the Remainder Buckets Algorithm only if n is considerably larger than k, otherwise brute force will be quicker

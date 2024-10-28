# Counting Triplets Divisible by a Given Number

**Problem:**
Given an array `a[]` of size `n` containing non-negative integers, find the total number of distinct triplets `(i, j, k)` such that `(a[i] + a[j] + a[k])` is divisible by a given integer `m`. Triplets where `i == j == k` are not allowed, i.e., the indices in each triplet should be unique (i.e., `i`, `j`, and `k` should all differ), and duplicate triplets in different orders should not be counted, it means, pairs `(i, j, k)` and `(j, i, k)` should be considered the same.

## Approach 1: Brute Force
The brute-force method involves checking every possible triplet in the array to see if their sum is divisible by `m`.

### Algorithm:
1. Initialize a counter, `count`, to zero.
2. Use three nested loops to iterate over every triplet `(i, j, k)` where `i < j < k`.
3. For each triplet, check if (a[i] + a[j] + a[k]) % m == 0. If true, increment the `count` counter.

### Code:
```java
public static int countPairsBruteForce(int[] a, int m) {
    int count = 0;
    int n = a.length;
    
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if ((a[i] + a[j] + a[k]) % m == 0)
                    count++;
    
    return count;
}
```
**Time Complexity:** O(n³)  
**Space Complexity:** O(1)

## Approach 2: Remainder Buckets and Counting
Since we’re interested in sums divisible by `k`, we can optimize using **modular property `remainder of sums = sum of remainder % m`**, if the sum of remainders `(a[i] % m)`, `(a[j] % m)`, and `(a[k] % m)` is also divisible by `m`. By distributing elements into **remainder buckets: `a[i] % m`** , we can efficiently compute valid triplets using combinatorial counting within and across these remainder buckets.

### Key Insight:
- For any three elements a[i], a[j] and a[k],
```
(a[i] + a[j] + a[k]) % m = (((a[i] + a[j]) % m) + (a[k] % m)) % m
                         = ((((a[i] % m) + (a[j] % m)) % m) + (a[k] % m)) % m
                         = LHS
```
resolves LHS into range (0, 2m-2), which equate to 0 if their remainder sum is either `0` or `m`.
- This gives three cases to consider, if r1 = a[i]%m, r2 = a[j]%m and r3 = a[k]%m :
    1. **All remainders are the same:** If r1=r2=r3, then we choose three elements from the same bucket
    2. **Two remainders are the same, one is different:** If r1=r2≠r3, then we need two from one bucket and one from another.
    3. **All three remainders are different:** r1≠r2≠r3, we take all three from different buckets

### Edge cases:
- Handle cases where m=1, as all sums will be divisible by m.
- If n<3, return 0 as we can’t form triplets.
- only consider i < j < k. If j > k pass through it without doing anything

### Algorithm:
1. Build the `cnt` array: `cnt[i]` holds the count of elements where `a[i] % m = r`.
2. Use nested loops over the possible remainder values to count triplets that satisfy `(a[i] % m + a[j] % m + a[k] % m) % m == 0`.

### Code:
```java
public static int countTripletsUsingBuckets(int[] a, int m) {
    int n = a.length;
    int[] cnt = new int[m];
    Arrays.fill(cnt, 0);
    
    for (int num : a) cnt[num % m]++;
    
    int count = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            int k = (m - (i + j) % m) % m;
            if (j > k) continue;
            if (i == j && j == k) count += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
            else if (i == j) count += cnt[i] * (cnt[i] - 1) / 2 * cnt[k];
            else if (j == k) count += cnt[j] * (cnt[j] - 1) / 2 * cnt[i];
            else count += cnt[i] * cnt[j] * cnt[k];
        }
    }
    
    return count;
}
```
### Note:
`else if (i == k) ans += cnt[i]*(cnt[i]-1)/2  * cnt[j];` case is not considered because this condition won't get created

**Time Complexity:** O(n + m²) (efficient when `m` is smaller than `n`)  
**Space Complexity:** O(m)

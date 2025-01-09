# Counting Triplets Divisible by a Given Number

**Problem:**
Given an array `a[]` of size `n` containing non-negative integers, find the total number of distinct triplets `(i, j, k)` such that `(a[i] + a[j] + a[k])` is divisible by a given integer `m`. Each index of a triplet should be unique (i.e., `i`, `j`, and `k` should all differ), and duplicate triplets in different orders should not be counted, it means, pairs `(i, j, k)` and `(j, i, k)` should be considered the same.

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
Since we’re interested in sums divisible by `k`, we can optimize using **modular property `remainder of sums = sum of remainder % m`**.

### Key Insight:
- We want to count all unique triplets `(i, j, k)` in the array such that `(a[i] + a[j] + a[k]) % m = 0` where `i`, `j`, and `k` are distinct indices. Breaking it down using modular addition property
```
(a[i] + a[j] + a[k]) % m = (((a[i] + a[j]) % m) + (a[k] % m)) % m
                         = ((((a[i] % m) + (a[j] % m)) % m) + (a[k] % m)) % m
                         = (((r1 + r2) % m) + r3) % m
                         = LHS
```
We can observe that instead of focusing on specific values, we can focus on **remainders** when each element is divided by `m` and grouped based on modular congruence into buckets.
- This gives us a **count of each remainder**, which is easier to work with than individual values when forming triplets. By storing frequencies of each remainder, we avoid repeatedly iterating over the array to find triplets, saving time.
- This approach simplifies the problem and resolves LHS into range `(0, 2m-2)`. With `r1` and `r2` bounded in `(0, m-1)` and `r3` in complementary `(0, m-1)` range.
- equating LHS to 0 will only be satisfied if sum of remainders is either `0` or `m`
- This gives three cases to consider,
  1. **All remainders are the same:** If `r1=r2=r3`, then all three of them will be `0`. Thus, we choose three elements from that same bucket.
  2. **Two remainders are the same, one is different:** If `r1=r2≠r3`, then we need two from one bucket and one from another complementary bucket.
  3. **All three remainders are different:** `r1≠r2≠r3`, we take all three from different buckets

### Algorithm:
#### Step 1: Count Frequencies of Each Remainder
1. We create an array `cnt` of size `m`, where `cnt[r]` will store the number of elements in `a` with remainder `r` when divided by `m`.
2. For each element in the array, calculate the remainder when it is divided by `m`, and increment the corresponding count in `cnt`.

#### Step 2: Generate Triplets from Remainder Combinations
1. Using three nested cases, we determine the valid combinations of remainders `(i, j, k)` and calculate the number of ways to form triplets for each case.
2. **Cases**:
- The outer loop iterates over each possible remainder `i`, the inner loop over each `j >= i`, and we calculate `k` based on `i` and `j`.
  - **Case 1**: All three remainders are the same (`i == j == k`).
    - Here, all triplet elements share the same remainder. This can only happen if `cnt[i] >= 3`. The number of triplets is calculated as `cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6`
    - This formula is a combination formula for choosing 3 items from `cnt[i]` items.

  - **Case 2**: Two remainders are the same (`i == j != k`).
    - In this case, two elements have the same remainder, and the third element has a different remainder. This scenario is counted as `cnt[i] * (cnt[i] - 1) / 2 * cnt[k]`
    - This formula chooses two items from `cnt[i]` items and one item from `cnt[k]` items.

  - **Case 3**: All three remainders are different (`i != j != k`).
    - Each element in the triplet has a different remainder. The count of such triplets is `cnt[i] * cnt[j] * cnt[k]`

3. **Avoiding Redundancies**: By structuring the loops to check only `j >= i` and `k >= j`, we maintain order among `i`, `j`, and `k`, avoiding duplicate triplet counts and ensure that each unique triplet combination is counted exactly once, without needing additional conditions.

### Edge cases:
- Handle cases where m=1, as all sums will be divisible by m.
- If n<3, return 0 as we can’t form triplets.
- only consider i < j < k. If j > k pass through it without doing anything

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
`else if (i == k) ans += cnt[i]*(cnt[i]-1)/2  * cnt[j];` case is not considered because i = k != j won't occur because i <= j <= k

**Time Complexity:** O(n + m²), counting remainders takes O(n), and checking all remainder combinations takes O(m^2). (efficient when `m` is smaller than `n`)
**Space Complexity:** O(m)

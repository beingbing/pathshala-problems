# Max Gap Problem: Bucketing Approach

## Problem
Given an array of integers, you need to find the maximum consecutive difference between two elements in sorted order. 

**Example 1**
- **Input:** `arr = {3, 6, 9, 1}`
- **After sorting:** `{1, 3, 6, 9}`
- **Consecutive differences:** `{2, 3, 3}`
- **Output:** Maximum difference = `3`

## Approach 1: Sorting
- **Steps:**
  - Sort the array.
  - Traverse the sorted array and record the maximum difference between consecutive elements.
  - **Time complexity:** O(n log n) for sorting + O(n) traversal = **O(n log n)**

While this works, What if we are not allowed to perform sorting or time constraint is to get it done with linear time complexity. We can improve the solution using a bucketing approach.

## Approach 2: Bucketing

### Pre-requisite: Understanding the Minimum Possible Gap

To find the minimum possible value of the maximum gap, we need three pieces of information:
1. **Largest element (max)**
2. **Smallest element (min)**
3. **Number of elements (n)**

For example:
- If `max = 7`, `min = 1`, and `n = 3`, the possible consecutive gaps can be found out by:
  - There is only one element missing, so let's see by hit and trial which number gives us the answer.
  - if the third element is `2`, consecutive gaps will be `{1, 5}`. The largest gap is `5`
  - if the third element is `3`, consecutive gaps will be `{2, 4}`. The largest gap is `4`
  - if the third element is `4`, consecutive gaps will be `{3, 3}`. The largest gap is `3`
  - Thus, the minimum possible maximum gap is `3` with third element as `4`

The formula to calculate this "minimum possible gap" is:
```
gap = (max - min) / (n - 1)
```
If this value is not an integer, the real maximum gap will be slightly larger due to uneven spacing between some elements.

### Approach Explained: Bucketing with Gap Calculation

**Key Idea:**  
By calculating the smallest possible gap and distributing elements into "buckets" we can avoid fully sorting the array. We only need to track the maximum and minimum values within each bucket and find the maximum difference between the maximum of one bucket and the minimum of the next.

Each bucket's starting and ending elements will be `[min, min-gap+1], [min + gap, min + 2*gap - 1], ... [min + (n-2)*gap, max-1], [max, max+gap-1]`. The Last bucket will only have one element, kept it just for the ease of calculation.

### Steps:
1. **Calculate Minimum Gap**  
   Using the formula `gap = (max - min) / (n - 1)`, calculate the minimum possible consecutive gap.
   If it's not an integer, round it up using `ceil()`, because some gaps will be larger than others.

2. **Create Buckets**  
   Divide the range from `min` to `max` into buckets, where each bucket can hold elements with a range of size `gap`.

3. **Distribute Elements into Buckets**  
   Assign each element from the array into its corresponding bucket based on the formula:
   ```
   bucket_index = (element - min) / gap
   ```

4. **Track Bucket Min/Max**  
   Maintain two arrays: `minArr` and `maxArr` to store the minimum and maximum elements of each bucket.

5. **Calculate Maximum Gap**  
   Finally, iterate over the buckets and compute the maximum difference between the maximum value of one bucket and the minimum value of the next bucket.

### Example walkthrough
given array - {20, 25, 27, 33, 65, 70}

**step 1:** min gap = (70-20)/(6-1) = 10

**step 3:** distribute given array elements into buckets using bkt_num = (a[i]-min)/gap
```
[20, 29] - 20, 25, 27
[30, 39] - 33
[40, 49]
[50, 59]
[60, 69] - 65
[70, 79] - 70
```

**step 4:** find largest and smallest element from each bucket.
```
            min     max
[20, 29] -  20,     27
[30, 39] -  33
[40, 49]
[50, 59]
[60, 69] -  65
[70, 79] -  70
```

**step 5:** tracking min of (i+1)th bucket - max of ith bucket will contribute to our answer

max of {33-27, 65-33, 70-65} = max of {6, 32, 5} so our answer is 32

### Code Implementation

```java
int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;
    
    // Step 1: Find the max and min elements
    int maxNum = INT_MIN, minNum = INT_MAX;
    for (auto ele : nums) {
        maxNum = max(maxNum, ele);
        minNum = min(minNum, ele);
    }
    if (maxNum == minNum) return 0;

    // Step 2: Calculate the minimum possible gap
    int gap = (maxNum - minNum) / (n - 1);
    if ((maxNum - minNum) % (n - 1) != 0) gap++;

    // Step 3: Initialize bucket arrays
    vector<int> minArr(n, INT_MAX), maxArr(n, INT_MIN);

    // Step 4: Place elements in buckets
    for (auto ele : nums) {
        int bkt = (ele - minNum) / gap;
        minArr[bkt] = min(minArr[bkt], ele);
        maxArr[bkt] = max(maxArr[bkt], ele);
    }

    // Step 5: Find maximum gap by comparing bucket max and min
    int ans = INT_MIN, prev = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (minArr[i] == INT_MAX) continue;  // Skip empty buckets
        if (prev == INT_MIN) prev = maxArr[i];
        else {
            ans = max(ans, minArr[i] - prev);
            prev = maxArr[i];
        }
    }
    return ans;
}
```

- **Time Complexity:** O(n), where n is the number of elements (since we avoid sorting).
- **Space Complexity:** O(n) for bucket arrays.

### Summary
Using the bucketing approach allows us to solve the problem in linear time by leveraging the minimum possible gap between elements. This avoids the need for sorting and efficiently calculates the maximum consecutive difference.

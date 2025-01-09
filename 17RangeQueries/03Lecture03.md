# Sparse Table

### Approach 4:
- Store minimum of all those subarrays whose size is a power of 2.
- Create a 2D matrix where first index will signify the start of range and second index will signify the length of range for which matrix value is minimum
- But second index will be in power of 2. So we can modify it to store power of 2 instead of its actual value when power of 2 is calculated.
- So, range of i will be `[0, n-1]` and range of j will be `[0, log n]`
- So, the equation will be -
```
min[i,j] = { min[i][j-1], min[i + 2^(j-1)][j-1], ... }
```

#### Complexity
1. pre-computation: O(n log n)
2. query: O(log n)
3. update query: O(n log n)
4. space: O()
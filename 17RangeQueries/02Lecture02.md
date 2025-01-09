# Square Root Decomposition
## Example: Problem
Given an array of n elements and Q queries. Queries are of two types, either you will be asked to give minimum of elements between given indexes (inclusive), or you will be asked to replace an array element with provided value on a given index. Answer each query.

## Solution
### Approach 1
- For each query of type 1 run a loop from index i to j and calculate the min
- For each query of type 2 update original array and replace the element with given value.

#### Complexity
1. Pre-computation: O(1) // no pre-computation done
2. Processing queries: O(n)
3. Space: O(1)

### Approach 2: Pre-computation
- Create a 2D matrix where first index will signify the start of range and second index will signify the end of range for which matrix value is minimum

#### Complexity
1. Pre-computation: O(n^2)
2. Processing calculation queries: O(1)
3. Processing update queries: O(n^2)
3. Space: O(n^2)

## Analysis
- The use of matrix is overdone, as we are not even utilizing cells below the main diagonal. Because the ending point of a range cannot be smaller than the starting point.

### Approach 3: Break array into buckets (Square-root decomposition)
- Decide on the number of buckets
- Compute the size of each array using: array-size / buckets-count
- Maintain another array of bucket size, where each cell signifies a bucket.
- To decide which cell of original array belong in which bucket, we can use: index/bucket-size.
- given indexes of a range query will fall either at the start of a bucket or in between.
  - If indexes falls in between, then a bucket is partially included
  - So, at max any range query can involve 2 partial buckets and numerous complete buckets for which we already has a pre-computed value.
  - So, we just need to perform computation on partial buckets, considering bucket size to be K. The time taken will be 2K.
  - So, computation-wise each query can be broken into: 2 * bucket-size + number-of-complete-buckets (Part-1 + Part-2)
- The whole pre-computation hinges on number of buckets created. Putting a fairly large number of buckets will shoot up Part-2 and putting a lower number will shoot up Part-1.
- The sweet spot for number of buckets is sqrt(n).
- As no-of-buckets * size-of-each-bucket = N. Hence, if no. of buckets are sqrt(n) then size of each bucket will also be sqrt(n).

#### Complexity:
1. Pre-computation: O(sqrt(n))
2. Processing calculation queries: O(sqrt(n))
3. Processing update queries: O(1)
4. Space: O(sqrt(n))

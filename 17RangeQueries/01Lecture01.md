# Intro to Range Queries
We already did Problem based on queries asked on a given range for a provided array, in solving them we used to do pre-computation so that each queries can be answered as early as possible.

But in those problems, we just accepted queries concerning some calculation on given data, however, what if we also need to deal with queries which can also modify the provided data for a given range in-between queries concerning calculations.

In case of update queries, the time computation will increase back to O(n) to update the pre-computed calculation accordingly.

Hence, both in-query calculation and pre-computation approaches become equally worse, and we are unable to decide on which to use if no information on trade-off is provided.

## Example: Problem
Given an array of n elements and Q queries. Queries are of two types, either you will be asked to give sum of elements between given indexes (inclusive) or you will be asked to replace an array element with provided value on a given index. Answer each query.

### Input
- First line will contain n and Q, number of elements in array and number of queries
- Second line will contain n elements
- Next Q lines will contain three space separated integers.
  - First integer will signify the type of operation (1 or 2)
  - Operation 1 will ask you to give sum of elements between indexes indicated by second and third integers.
  - Operation 2 will ask you to replace the element indicated by second integer by value indicated by third integer.
```
8 5
1 2 3 4 5 6 7 8
1 2 4
1 4 6
1 1 3
2 5 9
2 4 14
1 3 6
```

### Output
- For each query of type 1 output the sum of elements in given range.
```
9
15
6
32
```

## Solution
### Approach 1
- For each query of type 1 run a loop from index i to j and calculate the sum
- For each query of type 2 update original array and replace the element with given value.

#### Complexity
1. Pre-computation: O(1)
2. Processing queries: O(n)
3. Space: O(1)

### Approach 2
- Perform pre-computation and build a prefix sum array.
- For each query of type 1, find the sum from prefix array.
- For each query of type 2, update original array as well as prefix sum array

#### Complexity
1. Pre-computation: O(n)
2. Processing queries: O(1) for type 1, O(n) for type 2
3. Space: O(n)

## Analysis
As we can see, our smart approach is performing worse than the brute-force approach. That's because update queries will render the pre-computation useless. Pre-computation is not the way to go when update queries are involved.

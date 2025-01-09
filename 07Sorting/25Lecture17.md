# application of inversion count
## Problem 1
given an integer array of n elements. Sort it using insertion sort and provide inversion count. A pair (a[i],a[j]) is said to be in inversion if: a[i] > a[j] and i < j with 0 <= i, j < n

### Solution
- applying actually insertion sort will take quadratic time, and we need a way to do it with a better time complexity.
- for insertion sort, number of swaps happening to put new number in its right position will give us the inversion count.

Q. how to calculate inversion count in bubble sort

2. given int arr of n elements, find number of pairs i, j such that
- i < j
- a[i] > 2*a[j]
- 0 <= i,j < n

cnt = 0
k = s1
for (j=s2; j<=e2) {
    while (k <= e1 && a[k] <= 2*a[j]) k++
    cnt += e1-k+1
}

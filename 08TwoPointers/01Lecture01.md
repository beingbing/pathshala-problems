# pair sum - 1

given an array and a sum, find two numbers in array whose sum equals sum.
such that a[i] + a[j] = sum, where i != j

M1 -
O(n^2)
run two loops and check all possible pairs

M2 -
O(nlogn)
- sort it
- for each elements run BS for sum-ele in remaining array.

M3 -
O(nlogn)
- sort it
- run two variables from both end and do -
    - proceed lower element pointing variable forward if obtained sum < required sum
    - proceed bigger element pointing variable backward if obtained sum > required sum


criteria need to fulfill to succussfully implement two pointers method -
- how many pointers needed ?
- from where to initialize them
- logic to move them


code -
i = 0, j = n-1
while(i<j) {
    sum = a[i] + a[j]
    if (k == sum) return true;
    else if (k > sum) i++
    else j--
}

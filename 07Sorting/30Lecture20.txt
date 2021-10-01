~~ applications of partition ~~

1. given an integer array of n elements, push all the 0s at the end.

e.g. -
1   0   3   -4  2   0   -7  9

M1 - 
- iterate and push all the zeroes in separate array and other elements in separate arr
- push non-zero elements in original array then push all 0s

M2 -
- iterate and push all non zero elements in separate arr
- overwrite original array and overwrite all remaining with 0s

TC = O(n)
SC = O(n)


M3 - use partition condition

i = 0, j = n-1
while (i <= j) {
    while (i < n && a[i] != 0) i++;
    while (j >= 0 && a[j] == 0) j--
    if (i < j) swap(a[i], a[j])
}


if problem says you to maintain the relative order then -

i = 0, cnt = 0
while (i < n) {
    if (a[i] != 0) {
        if (i != cnt) swap(a[i], a[cnt]);
        cnt++;
    }
    i++
}




2. given an array of positive and negative elements segregate all positives on left and
all negatives to the right, while maintaining the relative order.

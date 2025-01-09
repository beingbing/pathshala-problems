~~ application of inversion count ~~

1. given an array, you are sorting using insertion sort. 
count of swaps will give us count of inversion.

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

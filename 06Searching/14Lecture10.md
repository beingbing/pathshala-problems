~~ kth smallest in array - 1 ~~

It is also an implementation of 'binary search on answer'

given an array and an int k, find the kth smallest element in array

for (int i{0}; i<n; i++) {
    int smaller = 0, equal = 0;
    for (int j{0}; j<n; j++) {
        if (a[j]<a[i]) smaller++;
        else if (a[j]==a[i]) equal++;
    }
    int total = smaller+equal;
    if (total >= k && smaller < k) return a[i];
}

TC = O(n^2)

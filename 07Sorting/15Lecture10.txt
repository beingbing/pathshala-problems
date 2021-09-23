~~ smallest subarray ~~

given arr with n elements, it only contains positive elements.
given an int k, return the length of smallest subarray with sum >= k

for (i{0}; i<n; i++) {
    int j // ending point
    l = i, h = n-1
    while (l <= h) {
        m = (l+h)/2
        int k = a[m] - a[i-1]
        if (k < target) l = m+1
        else {
            l = a[m-1] - a[i-1]
            if (l < target) return m;
            else h = m-1
        }
    }
}

TC = O(nlogn)

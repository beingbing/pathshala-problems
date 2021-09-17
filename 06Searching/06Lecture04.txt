~~ search in sorted rotated array ~~

given a sorted rotated array with distinct elements, find the index of given key.

pivot detection:

logic -
pivot will be the only element with arr[m] > arr[m+1] holding true

code -
l = 0, h = n-1
while (l <= h) {
    m = l + (h-l)/2
    if (a[m] <= a[n-1]) h = m-1;
    else {
        if (a[m] > a[m+1]) return m;
        else l = m+1;
    }
}

now, you can divide your array in two parts based on pivot, apply binary search on the part which
you think will contain the ansewr and get the answer.

food for thought -
what if repeatation is allowed

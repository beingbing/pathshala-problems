~~ repeated element ~~ (SEEN IN MULTIPLE INTERVIEWS)

given sorted arr of n (n >= 2), elements will belong in [1, n-1].
All elements will come once, but exactly 1 element will come twice.
find the element which will come twice.

sample example -
n = 8

    1   2   3   4   5   5   6   7
    0   1   2   3   4   5   6   7

here we can see, both left and right sides of answer holds different conditions which can help us in
deciding in which direction to move if we go with binary search.

left side of answer -> a[i] = i+1
right side of answer -> a[i] = i

so, our answer will be first element for which a[i] == i
or, our answer will be last element for which a[i] == i+1

code -

low = 0, high = n-1
while (low <= high) {
    int mid = low + (high - low)/2
    if (a[mid] == mid+1) {
        if (a[mid] == a[mid+1]) return mid;
        else low = mid+1;
    } else {
        if (a[mid-1] == a[mid]) return mid;
        else high = mid-1;
    }
}

or,

low = 0, high = n-1
while (low <= high) {
    int mid = low + (high - low)/2
    if (a[mid] == mid) high = mid - 1;
    else {
        if (a[mid] == a[mid+1]) return mid;
        else low = mid+1;
    }
}

This shows that, binary search is not entirely dependent on elements being sorted, if you can
establish a relation which can conclude in which direction to proceed then we can apply BS.


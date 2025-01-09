~~ kth smallest in array - 2 ~~

In last solution, we were considering all the elements as a potential candidate and iterating to
find there count, but if we have found a count for a previous number whose count is less than k,
and if we currently have a number which is smaller than the previous number, then definetly it's
count will be lesser than the previous number, so it can never be our answer.
similarly,
if previously we have seen that a numbers count is greater than k and current number is greater
than previous number then its count will definetly be greater than k.
so, here
we get a monotonicity on the basis of results we got earlier.
if a number is greater then the previously obtained count for a number then decide
whether we need to go with a bigger number or a smaller number as a candidate.

int countNums(int x) {
    int cnt = 0;
    for (int i{0}; i<n; i++) if (a[i] <= x) cnt++;
    return cnt;
}

the above function is a monotonic function, for a bigger input, output will be either same or it will
be greater, it can never be less, hence, it is a monotonically increasing function.

so, we can apply binary search here,

but, we still need a domain in which our binary search will function so that we can have our low and high
values for each iteration.

for that, we can consider, minimum and maximum elements of the array as our domain, as we are sure that
our answer can never go out of this.

l = min, h = max
while (l <= h) {
    m = (l+h)/2
    cnt = countNums(m);
    if (cnt < k) l = m+1
    else {
        cnt1 = countNums(m-1);
        if (cnt1 < k) return m
        else h = m-1
    }
}

TC = O(nlog(max-min))

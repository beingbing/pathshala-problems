# smallest subarray
## Problem
Given an integer array containing n positive elements, also given an integer k. Find the length of smallest subarray with sum >= k

Approach 1: Brute-force
maintain a running sum loop over all possible value of starting and ending indices of subarray and find the smallest length with sum >= k

int sum, ans = INT_MAX;
for (i: 0 to n-1) {
    sum = 0;
    for (j: i to n-1) {
        sum += a[j];
        if (sum >= k) ans = min(ans, j-i+1);
    }
}
return ans;

TC = O(n^2)
SC = O(1)

Approach 2:
We haven't used the fact that all elements are positive in above approach, hence, getting a prefix sum of array will give us a strictly increasing array on which Binary Search can be applied. 

for (i{0}; i<n; i++) { // i: starting point of subarray
    int j // ending point of subarray
    l = i, h = n-1
    while (l <= h) {
        m = (l+h)/2 // candidate for j
        int sum = ps[m] - ps[i-1]
        if (sum < k) l = m+1
        else {
            // not correct
            // sum = ps[m-1] - ps[i-1]
            // if (sum < k) return m;
            else h = m-1;
        }
    }
}

TC = O(nlogn)

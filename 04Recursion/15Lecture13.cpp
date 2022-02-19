// find max of an array using divide and conquer

// recursive relation -
// T(n) = 2T(n/2) + c

#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int> &ar, int strt, int end) {
    // termination condition
    if (strt == end) return ar[strt];
    // divide step
    int mid = strt + (end - strt) / 2;
    int lft = findMax(ar, strt, mid);
    int rgt = findMax(ar, mid + 1, end);
    // conquer step
    return max(lft, rgt);
}

int main() {
    vector<int> arr = {7, 1, 4, 3, 2, 6, 5};
    int mx = findMax(arr, 0, 6);
    cout << mx << endl;
    return 0;
}

// SC = T(logn)

// no of leaves = n, no of nodes above it n/2, ....
// so, n + n/2 + n/4 + .... => O(N)
// as every step is doing O(1) work, so O(N*1) = TC
// TC = O(N)

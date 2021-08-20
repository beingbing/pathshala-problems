// find max of an array using divide and conquer

#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int> &ar, int strt, int end) {
    // cout << "$: " << strt << " " << end << endl;
    if (strt == end) return ar[strt];
    int mid = strt + (end-strt)/2;
    int lft = findMax(ar, strt, mid);
    int rgt = findMax(ar, mid+1, end);
    return max(lft, rgt);
}

int main() {
    vector<int> arr = {7,1,4,3,2,6,5};
    int mx = findMax(arr, 0, 6);
    cout << mx << endl;
    return 0;
}
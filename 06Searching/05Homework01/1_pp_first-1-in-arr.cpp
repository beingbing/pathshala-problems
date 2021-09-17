/*

Given a sorted array consisting of 0′s and 1′s. The task is to print the index of first 1 in the given
array. You must write an algorithm with O(log(n)) runtime complexity.

Input Format
The first line of input contains N, size of the array
The second line of input contains N space-separated array elements

Constraints
1 ≤ N ≤ 10^5
0 ≤ nums[i] ≤ 1

Output Format
Print index of the first 1 or print −1.

*/

#include <iostream>
#include <vector>
using namespace std;

int firstPosition(vector<int> &nums, int &n, int &target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) high = mid-1;
        else if (nums[mid] < target) low = mid+1;
        else {
            if (mid == 0) return mid;
            else if (nums[mid-1] != target) return mid;
            else high = mid-1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i{0}; i<n; i++) cin >> vec[i];
    int target = 1;
    int frst = firstPosition(vec, n, target);
    if (frst == -1) cout << frst << endl;
    else cout << frst+1 << endl;
    return 0;
}
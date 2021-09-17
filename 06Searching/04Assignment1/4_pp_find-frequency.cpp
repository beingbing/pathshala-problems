/*

Given an array of integers, nums sorted in ascending order, and a target value. Print the number of
occurrences of the target in the given array. You must write an algorithm with O(log(n)) runtime complexity.

Input Format
The first line of input contains N, size of the array
The second line of input contains N space-separated array elements
The third line of the input contains a single integer T denoting the number of test cases.
The description of T test cases follows.
Each test case consists of a positive integer target

Constraints
1 ≤ N ≤ 10^5
1 ≤ nums[i], target ≤ 10^9
1 ≤ T ≤ 10^5

Output Format
Print the number of occurrences of target in the given array nums

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

int lastPosition(vector<int> &nums, int &n, int &target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) high = mid-1;
        else if (nums[mid] < target) low = mid+1;
        else {
            if (mid == n-1) return mid;
            else if (nums[mid+1] != target) return mid;
            else low = mid+1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i{0}; i<n; i++) cin >> vec[i];
    int t;
    cin >> t;
    while (t--) {
        int target;
        cin >> target;
        int frst = firstPosition(vec, n, target);
        int last = lastPosition(vec, n, target);
        if (frst == last && last == -1) cout << 0 << endl;
        else cout << last-frst+1 << endl;
    }
    return 0;
}
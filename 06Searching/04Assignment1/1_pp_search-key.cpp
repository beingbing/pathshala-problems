/*

Given an array nums of N integers which is sorted in ascending order, and an integer target,
write a program to search target in nums. If target exists, then print its index. Otherwise,
print −1. You must write an algorithm with O(log(n)) runtime complexity.

Input Format

The first line of input contains N, number of elements in the array
The second line of input contains N space-separated integers nums[0],........nums[N−1]
The third line of the input contains a single integer T denoting the number of test cases.
The description of T test cases follows.
Each test case consists of a positive integer target

Constraints

1 ≤ N ≤ 10^5
1 ≤ nums[i], target ≤ 10^9
1 ≤ T ≤ 10^5

Output Format
Print index of the target or if not found, print −1

*/

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int &n, int &target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i{0}; i < n; i++) cin >> nums[i];
    int t;
    cin >> t;
    while (t--) {
        int target;
        cin >> target;
        cout << binarySearch(nums, n, target) << endl;
    }
    return 0;
}
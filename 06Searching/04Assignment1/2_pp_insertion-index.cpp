/*

Given a sorted array of distinct integers nums and a target value, print the index if the target is found.
If not, print the index where it would be if it were inserted in order. You must write an algorithm with 
O(log(n)) runtime complexity.

Input Format

The first line of input contains N, size of the array.
The second line of input contains N space-separated array elements nums[0],........,nums[N−1]
The third line of the input contains a single integer T denoting the number of test cases. The description
of T test cases follows.
Each test case consists of a positive integer target

Constraints
1 ≤ N ≤ 10^5
1 ≤ nums[i], target ≤ 10^9
1 ≤ T ≤ 10^5

Output Format
For each testcase, print the index if the target is found. If not, print the index where it would be if it
were inserted in order.

*/

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int &n, int &target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) high = mid-1;
        else if (nums[mid] < target) low = mid+1;
        else return mid;
    }
    return low;
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
        cout << binarySearch(vec, n, target) << endl;
    }
    return 0;
}
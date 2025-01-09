/*

Given an array of integers nums sorted in ascending order, find the starting and ending position of a
given target value.
If target is not found in the array, return −1.
You must write an algorithm with O(log(n)) runtime complexity.

Input Format
The first line contains an integer N, number of elements in the array nums
The second line contains N space-separated integers nums[1],......, nums[N]
The third line of the input contains a single integer T denoting the number of test cases.
The description of T test cases follows.
Each test case consists of a positive integer target

Constraints
1 ≤ N ≤ 10^5
1 ≤ nums[i], target ≤ 10^9
1 ≤ T ≤ 10^5

Output Format
For each test case, print starting and ending index of the target value or −1

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
        if (frst == last && last == -1) cout << last << endl;
        else cout << frst+1 << " " << last+1 << endl;
    }
    return 0;
}

import java.util.Scanner;

public class TargetRangeFinder {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the size of the array
        int N = scanner.nextInt();
        int[] nums = new int[N];

        // Read the sorted array elements
        for (int i = 0; i < N; i++) {
            nums[i] = scanner.nextInt();
        }

        // Read the number of test cases
        int T = scanner.nextInt();
        StringBuilder result = new StringBuilder();

        // Process each test case
        for (int i = 0; i < T; i++) {
            int target = scanner.nextInt();
            int start = findFirstPosition(nums, target);
            if (start == -1) {
                // If start is -1, target is not in array, add -1 to result
                result.append("-1\n");
            } else {
                int end = findLastPosition(nums, target);
                result.append((start + 1)).append(" ").append((end + 1)).append("\n");
            }
        }

        System.out.print(result); // Print all results at once
        scanner.close();
    }

    // Binary search to find the first position of target
    private static int findFirstPosition(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        int firstPosition = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                firstPosition = mid;
                right = mid - 1; // Move left to find the first occurrence
            } else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return firstPosition;
    }

    // Binary search to find the last position of target
    private static int findLastPosition(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        int lastPosition = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                lastPosition = mid;
                left = mid + 1; // Move right to find the last occurrence
            } else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return lastPosition;
    }
}

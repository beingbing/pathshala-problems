/*

You are given an N*M binary matrix of 1s (representing soldiers) and 0s (representing civilians).
The soldiers are positioned in front of the civilians. That is, all the 1s will appear to the left
of all the 0s in each row. A row i is weaker than a row j if one of the following is true:
1. The number of soldiers in row i is less than the number of soldiers in row j
2. Both rows have the same number of soldiers and i<j

Print the indices of the k weakest rows in the matrix ordered from weakest to strongest.

Input Format
The first line of input contains N and M, denoting rows and columns of the matrix
The second line of input contains the binary matrix mat
The third line of the input contains a single integer T denoting the number of test cases.
The description of T test cases follows.
Each test case consists of a positive integer k, denoting number of weakest rows to be printed

Constraints
1 ≤ N, M ≤ 10^3
0 ≤ mat[i] ≤ 1
1 ≤ T ≤ N
1 ≤ k ≤ N

Output Format
Print the k weakest rows in each testcase

*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int firstPosition(vector<int> &nums, int &n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) low = mid+1;
        else if (nums[mid] < target) high = mid-1;
        else {
            if (mid == 0) return mid;
            else if (nums[mid-1] != target) return mid;
            else high = mid-1;
        }
    }
    return n;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> mat(rows, vector<int>(cols, 0));
    for (int i{0}; i<rows; i++) for (int j{0}; j<cols; j++) cin >> mat[i][j];
    multimap<int, int> mp;
    for (int i{0}; i<rows; i++) mp.insert({firstPosition(mat[i], cols, 0), i});
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        for (auto ele : mp) {
            cout << ele.second;
            k--;
            if (!k) break;
            else cout << " ";
        }
        cout << endl;
    }
    return 0;
}

import java.util.*;

public class Solution {

    // Helper function to count soldiers (1s) in a row using binary search
    private int countSoldiers(int[] row) {
        int left = 0;
        int right = row.length;

        // Binary search for the first 0 in the row
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (row[mid] == 1) left = mid + 1; // move right if mid is a soldier
            else right = mid; // move left if mid is civilian
        }
        // `left` will be the count of soldiers (number of 1s)
        return left;
    }

    public int[] weakestRows(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;

        // List to store pairs of (soldierCount, rowIndex)
        List<int[]> soldierCounts = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int soldiers = countSoldiers(mat[i]);
            soldierCounts.add(new int[] {soldiers, i});
        }

        // Sort based on soldier count and then by row index
        Collections.sort(soldierCounts, (a, b) -> {
            if (a[0] == b[0]) return Integer.compare(a[1], b[1]);
            else return Integer.compare(a[0], b[0]);
        });

        // Extract the row indices in the sorted order
        int[] result = new int[n];
        for (int i = 0; i < n; i++) result[i] = soldierCounts.get(i)[1];

        return result;
    }

    // Main method for testing
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case input
        int[][] mat = {
            {1, 1, 0, 0, 0},
            {1, 1, 1, 1, 0},
            {1, 0, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {1, 1, 1, 1, 1}
        };

        // Expected output: [2, 0, 3, 1, 4]
        System.out.println(Arrays.toString(solution.weakestRows(mat)));
    }
}

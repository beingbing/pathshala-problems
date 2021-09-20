#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {

    int upperBound(vector<int>& v, int& x, int& n) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (v[mid] <= x) low = mid + 1;
            else {
                if (mid == 0) return mid;
                if (v[mid - 1] < x) return mid;
                else high = mid - 1;
            }
        }
        return low;
    }

    int countNums(vector<vector<int>> &mat, int x, int &n) {
        int cnt = 0;
        for (int i{0}; i < n; i++) {
            // cnt += upper_bound(mat[i].begin(), mat[i].end(), x) - mat[i].begin();
            cnt += upperBound(mat[i], x, n);
        }
        return cnt;
    }

public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int mn{INT_MAX}, mx{INT_MIN};
        int n = mat.size();
        for (int i{0}; i < n; i++) {
            mn = min(mn, mat[i][0]);
            mx = max(mx, mat[i][n - 1]);
        }
        int low = mn, high = mx;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = countNums(mat, mid, n);
            if (cnt < k) low = mid + 1;
            else {
                int cnt1 = countNums(mat, mid - 1, n);
                if (cnt1 < k) return mid;
                else high = mid - 1;
            }
        }
        return -1;
    }
};
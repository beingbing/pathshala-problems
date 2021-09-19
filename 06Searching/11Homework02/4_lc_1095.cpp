/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 *
 */
class MountainArray {
public:
    int get(int index);
    int length();
};

class Solution {

    int findPivot(MountainArray &nums, int &n) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int m = nums.get(mid);
            if (mid == 0) {
                int p = nums.get(mid + 1);
                if (m > p) return mid;
                else low = mid + 1;
            } else if (mid == n - 1) {
                int l = nums.get(mid - 1);
                if (l < m) return mid;
                else high = mid - 1;
            } else {
                int p = nums.get(mid + 1);
                int l = nums.get(mid - 1);
                if (l < m && m > p) return mid;
                else {
                    if (m > p) high = mid - 1;
                    else low = mid + 1;
                }
            }
        }
        return n - 1;
    }

    int binarySearch(MountainArray &nums, int low, int high, int &k) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int m = nums.get(mid);
            if (m == k) return mid;
            else if (m > k) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }

    int revBinarySearch(MountainArray &nums, int low, int high, int &k) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int m = nums.get(mid);
            if (m == k) return mid;
            else if (m > k) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

public:
    int findInMountainArray(int target, MountainArray &ma) {
        int n = ma.length();
        int pivotIdx = findPivot(ma, n);
        int lhs, rhs;
        if (pivotIdx == n - 1) return binarySearch(ma, 0, n - 1, target);
        else if (pivotIdx == 0) return revBinarySearch(ma, 0, n - 1, target);
        else {
            lhs = binarySearch(ma, 0, pivotIdx, target);
            rhs = revBinarySearch(ma, pivotIdx + 1, n - 1, target);
        }
        if (lhs != -1) return lhs;
        else if (rhs != -1) return rhs;
        return -1;
    }
};
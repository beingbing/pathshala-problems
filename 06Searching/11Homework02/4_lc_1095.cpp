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

```java
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int length = mountainArr.length();

        // Step 1: Find the peak element index
        int peak = findPeakIndex(mountainArr, length);

        // Step 2: Search in the increasing part (left of the peak)
        int leftResult = binarySearch(mountainArr, target, 0, peak, true);
        if (leftResult != -1) {
            return leftResult;
        }

        // Step 3: If not found in left, search in the decreasing part (right of the peak)
        int rightResult = binarySearch(mountainArr, target, peak + 1, length - 1, false);
        return rightResult;
    }

    // Helper function to find the peak index using binary search
    private int findPeakIndex(MountainArray mountainArr, int length) {
        int left = 0, right = length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) left = mid + 1;
            else right = mid;
        }
        // left == right is the peak index
        return left;
    }

    // Helper function for binary search
    // isAscending indicates if the section is sorted in ascending or descending order
    private int binarySearch(MountainArray mountainArr, int target, int left, int right, boolean isAscending) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = mountainArr.get(mid);

            if (midValue == target) return mid; // Found the target

            if (isAscending) {
                if (midValue < target) left = mid + 1;
                else right = mid - 1;
            } else {
                if (midValue > target) left = mid + 1;
                else right = mid - 1;
            }
        }

        return -1;
    }
}
```
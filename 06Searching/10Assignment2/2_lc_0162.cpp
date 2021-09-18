#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        for (int i{1}; i<nums.size()-1; i++) {
            if (nums[i-1] < nums[i] && nums[i] > nums[i+1])
                return i;
        }
        return nums.size()-1;
    }
};

class SolutionM2 {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        if (n == 1) return 0;
        int low = 0, high = n-1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (mid == 0) {
                if (a[mid] >= a[mid+1]) return mid;
                else return mid+1;
            } else if (mid == n-1) {
                if (a[mid-1] <= a[mid]) return mid;
                else return mid-1;
            } else {
                if (a[mid-1] <= a[mid] && a[mid] >= a[mid+1]) return mid;
                else if (a[mid] < a[mid+1]) low = mid + 1;
                else if (a[mid-1] > a[mid]) high = mid - 1;
            }
        }
        return -1;
    }
};
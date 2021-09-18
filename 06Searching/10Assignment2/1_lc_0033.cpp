#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
          int mid = start + (end - start) / 2;
          if (nums[mid] == target) return mid;
          else if (nums[start] <= nums[mid]) {
             // these if else are due to rotation
            if (nums[start] <= target && target < nums[mid]) end = mid - 1;
            else start = mid + 1;
          }
          else {
             // these if else are due to rotation
            if (nums[mid] < target && target <= nums[end]) start = mid + 1;
            else end = mid - 1;
          }
        }
        return -1;
    }
};

// 1. loop over the array using start and end index
// 2. calculate mid
// 3. if mid is target, return ans
// 4. if mid is greater than start then left half is unrotated (doesn't contain pivot)
// 5. if target also belongs in left half, then search in there


class SolutionM2 {
    
    int findPivot(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] <= nums[n-1]) high = mid-1;
            else {
                if (nums[mid] > nums[mid+1]) return mid;
                else low = mid+1;
            }
        }
        return n-1;
    }
    
    int binarySearch(vector<int>& nums, int low, int high, int& k) {
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (nums[mid] == k) return mid;
            else if (nums[mid] > k) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        int pivotIdx = findPivot(nums);
        int n = nums.size();
        if (pivotIdx == n-1) return binarySearch(nums, 0, n-1, target);
        if (target == nums.back()) return nums.size()-1;
        else if (target < nums.back()) return binarySearch(nums, pivotIdx+1, n-1, target);
        else return binarySearch(nums, 0, pivotIdx, target);
        return -1;
    }
};
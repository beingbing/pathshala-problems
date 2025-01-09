#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size();
        if (n == 1) return a[0];
        int low = 0, high = n-1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (mid == 0) {
                if (a[mid] != a[mid+1]) return a[mid];
                else low = mid + 1;
            } else if (mid == n-1) {
                if (a[mid-1] != a[mid]) return a[mid];
                else high = mid - 1;
            } else if (a[mid-1] != a[mid] && a[mid] != a[mid+1]) {
                return a[mid];
            } else {
                int firstOccurence, secondOccurence;
                if (a[mid] == a[mid+1]) {
                    firstOccurence = mid;
                    secondOccurence = mid+1;
                } else {
                    firstOccurence = mid-1;
                    secondOccurence = mid;
                }
                if (firstOccurence%2 == 0) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
};


class SolutionM2 {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = nums[0];
        for (int i{1}; i<nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};
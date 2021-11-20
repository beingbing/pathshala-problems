#include <iostream>
#include <vector>
using namespace std;

class Solution {

    int findPairsCnt(int offset, vector<int>& nums, int& sz) {
        int cnt{0};
        // sliding window technique (compressed)
        for (int i{0}, j{0}; i<sz; i++) {
            while (j<sz && nums[j]-nums[i] <= offset) j++;
            cnt += j-i-1;
        }
        return cnt;
    }

public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n-1] - nums[0];
        while (low <= high) {
            int mid = low + (high - low)/2;
            int pairs = findPairsCnt(mid, nums, n);
            if (pairs < k) low = mid+1;
            else {
                int pairs2 = findPairsCnt(mid-1, nums, n);
                if (pairs2 < k) return mid;
                else high = mid-1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {7,2,1,4};
    int k = 4;
    Solution* obj = new Solution();
    cout << obj->smallestDistancePair(nums, k) << endl;
    return 0;
}
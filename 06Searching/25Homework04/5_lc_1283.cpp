#include <iostream>
#include <vector>
using namespace std;

class Solution {

    int divisonSum(vector<int>& nums, int divisor) {
        int sum{0};
        for (auto ele : nums) sum += ceil((ele*1.0)/divisor);
        return sum;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (divisonSum(nums, mid) > threshold) low = mid + 1;
            else {
                if (divisonSum(nums, mid+1) > threshold) return mid;
                else high = mid - 1;
            }
        }
        return low;
    }
};


int main() {
    vector<int> nums = {1,2,5,9};
    int threshold = 6;
    Solution obj;
    cout << obj.smallestDivisor(nums, threshold) << endl;
    return 0;
}

/*
If the sum > threshold, the divisor is too small.
If the sum <= threshold, the divisor is big enough.
*/

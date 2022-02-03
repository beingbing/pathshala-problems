/*

we cannot use top - bottom method here, as in that we need to make use of suffix array, but
here suffix array is not same all recursion cycles

in bottom - top approach, we can not keep a prefix array, as we will be needing two competing
values for similar cycles in order to accomodate cyclic nature.
and furthermore, one prefix array will be starting from one index ahead from other.

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {

    int maxSum(int fi, vector<int> &nums, int nd) {
        int fv = nums[fi];
        int sv = max(fv, nums[fi + 1]), cur;
        for (int i{fi + 2}; i <= nd; i++) {
            cur = max(nums[i] + fv, sv);
            fv = sv;
            sv = cur;
        }
        return sv;
    }

public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (!n) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(maxSum(0, nums, n - 2), maxSum(1, nums, n - 1));
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution obj;
    cout << obj.rob(nums) << endl;
    return 0;
}

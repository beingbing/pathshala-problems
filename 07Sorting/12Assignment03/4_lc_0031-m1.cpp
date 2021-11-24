#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
        for (k = n-2; k>=0; k--) if (nums[k] < nums[k+1]) break;
        if (k < 0) reverse(nums.begin(), nums.end());
        else {
            for (l = n-1; l>k; l--) if (nums[l] > nums[k]) break;
            swap(nums[k], nums[l]);
            reverse(nums.begin()+k+1, nums.end());
        }
    }
};

int main() {
    vector<int> nums = {5,10,6,4,9};
    Solution obj;
    obj.nextPermutation(nums);
    for (auto ele : nums) cout << ele << '\t';
    cout << endl;
    return 0;
}

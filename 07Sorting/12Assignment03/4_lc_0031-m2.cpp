#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), x = n-1, y;
        while (x > 0 and nums[x] <= nums[x-1]) x--;
        if (x > 0) {
            for (y = n-1; y>=x; y--) if (nums[y] > nums[x-1]) break;
            swap(nums[x-1], nums[y]);
            reverse(nums.begin()+x, nums.end());
        } else reverse(nums.begin(), nums.end());
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

// this is a pseudo hard problem, attempt it again
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> prfxMn(n, INT_MAX);
        prfxMn[0] = nums[0];
        for (int i{1}; i<n; i++) prfxMn[i] = min(prfxMn[i-1], nums[i]); // nums[i] candidate
        stack<int> stk;
        for (int j{n-1}; j >= 0; j--) {
            while (!stk.empty() && stk.top() < nums[j]) {
                if (prfxMn[j] < stk.top()) return true;
                stk.pop(); // too small for being nums[k]
            }
            stk.push(nums[j]); // no longer nums[j] candidate but can be nums[k] candidate
        }
        return false;
    }
};

int main() {
    vector<int> nums = {3, 1, 4, 2};
    Solution obj;
    cout << obj.find132pattern(nums) << endl;
    return 0;
}

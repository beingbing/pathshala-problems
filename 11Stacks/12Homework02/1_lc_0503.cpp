#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(), num;
        stack<int> s;
        vector<int> ans(n, -1);
        for (int i{0}; i<2*n; i++) {
            num = nums[i%n];
            while (!s.empty() && nums[s.top()] < num) {
                ans[s.top()] = num;
                s.pop();
            }
            if (i < n) s.push(i);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,2,3,4,3};
    Solution obj;
    vector<int> ans = obj.nextGreaterElements(nums);
    for (auto ele : ans) cout << ele << endl;
    return 0;
}

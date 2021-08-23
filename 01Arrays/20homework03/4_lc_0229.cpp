#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElementM1(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (auto ele : nums) 
            if (mp.find(ele) == mp.end()) mp.insert({ele, 1});
            else mp[ele]++;
        int val = n/3;
        vector<int> ans;
        for (auto ele : mp) if (ele.second >= val) ans.push_back(ele.first); 
        return ans;
    }

    vector<int> majorityElementM2(vector<int>& nums) {
        int count1 = 0,count2 = 0, candidate1 = INT_MAX, candidate2 = INT_MAX;
        for (int n: nums) {
            if (candidate1 != INT_MAX && candidate1 == n) count1++;
            else if (candidate2 != INT_MAX && candidate2 == n) count2++;
            else if (count1 == 0) {
                candidate1 = n;
                count1++;
            } else if (count2 == 0) {
                candidate2 = n;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        // 2nd pass
        vector<int> result;
        count1 = 0;
        count2 = 0;
        for (int n: nums) {
            if (candidate1 != INT_MAX && n == candidate1) count1++;
            if (candidate2 != INT_MAX && n == candidate2) count2++;
        }
        int n = nums.size();
        if (count1 > n/3) result.push_back(candidate1);
        if (count2 > n/3) result.push_back(candidate2);
        return result;
    }
};

int main() {
    Solution* obj = new Solution();
    vector<int> nums = {3,2,3};
    vector<int> ans = obj->majorityElementM2(nums);
    for (auto ele : ans) cout << ele << endl;
    return 0;
}
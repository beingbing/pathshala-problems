#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        deque<int> maxdq, mindq;
        int j = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (!maxdq.empty() && nums[i] > maxdq.back()) maxdq.pop_back();
            while (!mindq.empty() && nums[i] < mindq.back()) mindq.pop_back();
            maxdq.push_back(nums[i]);
            mindq.push_back(nums[i]);
            while (maxdq.front() - mindq.front() > limit) {
                if (maxdq.front() == nums[j]) maxdq.pop_front();
                if (mindq.front() == nums[j]) mindq.pop_front();
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {10,1,2,4,7,2};
    int limit = 5;
    Solution obj;
    cout << obj.longestSubarray(nums, limit) << endl;
    return 0;
}

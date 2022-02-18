#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        deque<int> maxdq, mindq;
        int back = 0;
        int ans = 0;
        for (int frnt = 0; frnt < nums.size(); frnt++) {
            while (!maxdq.empty() && nums[frnt] > maxdq.back()) maxdq.pop_back();
            while (!mindq.empty() && nums[frnt] < mindq.back()) mindq.pop_back();
            maxdq.push_back(nums[frnt]);
            mindq.push_back(nums[frnt]);
            while (maxdq.front() - mindq.front() > limit) {
                if (maxdq.front() == nums[back]) maxdq.pop_front();
                if (mindq.front() == nums[back]) mindq.pop_front();
                back++;
            }
            ans = max(ans, frnt - back + 1);
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

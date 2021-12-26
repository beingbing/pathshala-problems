#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        multiset<int> m;
        int bck = 0, ans = 1;
        for (int frnt = 0; frnt < nums.size(); frnt++) {
            m.insert(nums[frnt]);
            while (*m.rbegin() - *m.begin() > limit)
                m.erase(m.find(nums[bck++]));
            ans = max(ans, frnt - bck + 1);
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

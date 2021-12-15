#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxlen = 0, count = 0;
        mp[count] = -1;
        for (int i = 0; i < nums.size(); i++) {
            count = count + (nums[i] == 1 ? 1 : -1);
            if (mp.find(count) != mp.end()) maxlen = max(maxlen, i - mp[count]);
            else mp[count] = i;
        }
        return maxlen;
    }
};

int main() {
    vector<int> nums = {0,1,1,0,0,0,1,1,1,0};
    Solution obj;
    cout << obj.findMaxLength(nums) << endl;
    return 0;
}

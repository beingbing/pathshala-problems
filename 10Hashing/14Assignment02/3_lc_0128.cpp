#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
    int longestConsecutive(vector<int>& a) {
        unordered_map<int, int> m;
        int n = a.size(), ans = 0;
        for (auto ele : a) {
            if (m.find(ele) != m.end()) continue;
            int ls = 0, rs = 0;
            if (m.find(ele-1) != m.end()) ls = m[ele-1];
            if (m.find(ele+1) != m.end()) rs = m[ele+1];
            ans = max(ans, ls+rs+1);
            m[ele] = ls+rs+1;
            m[ele-ls] = 1+ls+rs;
            m[ele+rs] = 1+ls+rs;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    Solution obj;
    cout << obj.longestConsecutive(nums) << endl;
    return 0;
}

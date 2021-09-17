#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size(), last{n-1}, frst{0};
        int val;
        while (frst <= last) {
            val = a[frst] + a[last];
            if (val > target) last--;
            else if (val < target) frst++;
            else if (val == target) return {frst+1, last+1};
        }
        return {};
    }
};

// two pointer method
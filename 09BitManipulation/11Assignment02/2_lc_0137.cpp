#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& a) {
        long mask = 1L << 31, ans = 0;
        for (int i{31}; i>=0; i--) {
            int cnt = 0;
            for (int j{0}; j<a.size(); j++) if (a[j] & mask) cnt++;
            if (cnt%3 != 0) ans += mask;
            mask >>= 1;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,1,1,2,2,3,3,3,2,4};
    Solution obj;
    cout << obj.singleNumber(nums) << endl;
    return 0;
}
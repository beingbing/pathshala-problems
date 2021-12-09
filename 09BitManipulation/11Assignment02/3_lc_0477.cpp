#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& a) {
        int n = a.size(), ans = 0;
        long long mask = 1L << 31;
        for (int i{31}; i>=0; i--) {
            int cnt = 0;
            for (int j{0}; j<n; j++) if (mask & a[j]) cnt++;
            ans += cnt * (n-cnt);
            mask >>= 1;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {4,14,2};
    Solution obj;
    cout << obj.totalHammingDistance(nums) << endl;
    return 0;
}

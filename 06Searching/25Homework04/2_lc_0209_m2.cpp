// two-pointer solution
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {

public:
    int minSubArrayLen(int target, vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;
        int bck = 0, frnt = 0, sum = 0, mn = n+1;
        while (frnt < n) {
            cout << bck << " " << frnt << endl;
            sum += a[frnt++];
            while (sum >= target) {
                mn = min(mn, frnt - bck);
                sum -= a[bck++];
            }
        }
        return mn > n ? 0 : mn;
    }
};

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    Solution obj;
    cout << obj.minSubArrayLen(7, nums) << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), ans{INT_MIN}, mn{INT_MAX};
        int p1 = 0, p2 = n-1;
        while (p1 < p2) {
            mn = min(height[p1], height[p2]);
            ans = max(ans, mn*(p2-p1));
            height[p1] > height[p2] ? p2-- : p1++;
        }
        return ans;
    }
};

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution obj;
    cout << obj.maxArea(height) << endl;
    return 0;
}
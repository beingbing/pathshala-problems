#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    
    int findGCDM2(int a, int b) {
        int x = min(a, b);
        int y = max(a, b);
        if (x == 0) return y;
        if (y%x == 0) return x;
        return findGCDM2(x, y%x);
    }
    
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        for (auto ele : deck) mp[ele]++;
        vector<int> vec;
        for (auto kvp : mp) vec.push_back(kvp.second);
        int gcd = vec[0];
        int n = vec.size();
        for (int i{1}; i<n; i++) gcd = findGCDM2(gcd, vec[i]);
        if (gcd >= 2) return true;
        return false;
    }
};

int main() {
    vector<int> nums = {1,2,3,4,4,3,2,1};
    Solution* obj = new Solution();
    cout << obj->hasGroupsSizeX(nums) << endl;
    return 0;
}

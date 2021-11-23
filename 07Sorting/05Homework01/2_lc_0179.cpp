#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmpr(string& x, string& y) {
    return x+y > y+x;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vals;
        for (auto ele : nums) vals.push_back(to_string(ele));
        sort(vals.begin(), vals.end(), cmpr);
        string ans;
        for (auto ele : vals) ans += ele;
        while(ans[0]=='0' && ans.length()>1) ans.erase(0,1); // to trim leading zeroes
        return ans;
    }
};

int main() {
    vector<int> nums = {3,30,34,5,9};
    Solution obj;
    cout << obj.largestNumber(nums) << endl;
    return 0;
}

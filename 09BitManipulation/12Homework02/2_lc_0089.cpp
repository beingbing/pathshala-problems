#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int mask{0};
        vector<int> ans;
        ans.push_back(mask);
        for (int i{1}; i<=n; i++) {
            int len = ans.size();
            mask = 1L << (i-1);
            for (int j{len-1}; j>=0; j--) ans.push_back(mask + ans[j]);
        }
        return ans;
    }
};

int main() {
    int n = 4;
    Solution obj;
    vector<int> ans = obj.grayCode(n);
    for (auto ele : ans) cout << ele << endl;
    return 0;
}

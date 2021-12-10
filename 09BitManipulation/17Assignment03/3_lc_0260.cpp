#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& a) {
        int overallXOR = 0;
        for (auto ele : a) overallXOR ^= ele;
        int leastSetBit = 1;
        while (!(leastSetBit & overallXOR)) leastSetBit <<= 1;
        int n1 = 0;
        for (auto ele : a) if (ele & leastSetBit) n1 ^= ele;
        int n2 = overallXOR ^ n1;
        return {n1, n2};
    }
};

int main() {
    vector<int> a = {1,2,1,2,3,5,6,6};
    Solution obj;
    vector<int> ans = obj.singleNumber(a);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}

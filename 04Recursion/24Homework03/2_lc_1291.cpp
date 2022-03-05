#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digit = "123456789";
        vector<int> ans;
        int mnSz = to_string(low).size();
        int mxSz = to_string(high).size();
        for (int i{mnSz}; i <= mxSz; i++) {
            for (int j{0}; j < 10-i; j++) {
                int num = stoi(digit.substr(j, i));
                if (num >= low && num <= high) ans.push_back(num);
            }
        }
        return ans;
    }
};

int main() {
    Solution* obj = new Solution();
    vector<int> ans = obj->sequentialDigits(1000, 13000);
    for (auto ele : ans) cout << ele << endl;
    return 0;
}

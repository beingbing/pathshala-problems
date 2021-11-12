#include <vector>
#include <string>
using namespace std;

class Solution {
    vector<string> ans;

    void helper(string s, string tmp, int parts) {
        if (parts == 4 && s.size() == 0) ans.push_back(tmp.substr(0, tmp.size() - 1));
        if (parts == 4 || s.size() == 0) return;
        helper(s.substr(1), tmp + s.substr(0, 1) + '.', parts + 1);
        if (s.size() > 1 && s[0] != '0') {
            helper(s.substr(2), tmp + s.substr(0, 2) + '.', parts + 1);
            if (s.size() > 2 && stoi(s.substr(0, 3)) <= 255) {
                helper(s.substr(3), tmp + s.substr(0, 3) + '.', parts + 1);
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        if (n < 4 || n > 12) return ans;
        helper(s, "", 0);
        return ans;
    }
};
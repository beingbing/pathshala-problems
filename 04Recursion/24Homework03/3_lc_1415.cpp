#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
    vector<char> ch = {'a', 'b', 'c'};
    vector<string> ans;
    
    void helper(string str, int& n, int& k) {
        if (ans.size() == k) return;
        if (str.size() == n) {ans.push_back(str); return;}
        for (int i{0}; i<3; i++) {
            if (str.size() == 0 || str[str.size()-1] != ch[i])  {
                helper(str += ch[i], n, k);
                str.pop_back();
            }
        }
    }
    
public:
    string getHappyString(int n, int k) {
        string str;
        helper(str, n, k);
        if (ans.size() == k) return ans.back();
        return "";
    }
};

int main() {
    Solution* obj = new Solution();
    string ans = obj->getHappyString(1, 3);
    cout << ans << endl;
    return 0;
}

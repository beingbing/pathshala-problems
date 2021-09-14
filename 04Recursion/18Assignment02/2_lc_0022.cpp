#include <vector>
#include <string>
using namespace std;

class Solution {
    vector<string> ans;
    
    void generate(string temp, int l, int r, int& n) {
        if (temp.size() == 2*n) {ans.push_back(temp);return;}
        if (l == r) generate(temp+'(', l+1, r, n);
        else if (l > r) {
            if (l == n) generate(temp+')', l, r+1, n);
            else {
                generate(temp+'(', l+1, r, n);
                generate(temp+')', l, r+1, n);
            }
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        generate("", 0, 0, n);
        return ans;
    }
};
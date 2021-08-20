#include <iostream>
#include <vector>
using namespace std;

class Solution {

    void generateParenthesis(string str, int l, int r, int &n) {
        if (str.size() == 2*n) {
            ans.push_back(str);
            return;
        }
        if (l == r) generateParenthesis(str+'(', l+1, r, n);
        else if (l > r)
            if (l == n) generateParenthesis(str+')', l, r+1, n);
            else {
                generateParenthesis(str+'(', l+1, r, n);
                generateParenthesis(str+')', l, r+1, n);
            }
    }

public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        generateParenthesis("", 0, 0, n);
        return ans;
    }
};
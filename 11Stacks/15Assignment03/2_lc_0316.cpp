#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;
        vector<int> freq(26, 0);
        vector<bool> present(26, false);
        for (auto ele : s) freq[ele - 'a']++;
        for (auto ele : s) {
            freq[ele - 'a']--;
            if (present[ele - 'a']) continue;
            while (!stk.empty() && ele < stk.top() && freq[stk.top() - 'a'] > 0) {
                present[stk.top() - 'a'] = false;
                stk.pop();
            }
            stk.push(ele);
            present[stk.top() - 'a'] = true;
        }
        string str;
        while (!stk.empty()) str += stk.top(), stk.pop();
        reverse(str.begin(), str.end());
        // cout << str << endl;
        return str;
    }
};

int main() {
    string s = "cbacdcbc";
    Solution obj;
    cout << obj.removeDuplicateLetters(s) << endl;
    return 0;
}

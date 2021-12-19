#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int n = s.size();
        for (int i{0}; i < n; i++)
            if (!stk.empty() && s[i] == ']' && stk.top() == '[') stk.pop();
            else if (!stk.empty() && s[i] == ')' && stk.top() == '(') stk.pop();
            else if (!stk.empty() && s[i] == '}' && stk.top() == '{') stk.pop();
            else stk.push(s[i]);
        return stk.empty();
    }
};

int main() {
    string s = "()[]{}";
    Solution obj;
    cout << obj.isValid(s) << endl;
    return 0;
}

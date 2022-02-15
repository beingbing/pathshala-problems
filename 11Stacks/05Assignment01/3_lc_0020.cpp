#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto &ele : s) {
            if (ele == ')') {
                if (stk.empty() || stk.top() != '(') return false;
                stk.pop();
            } else if (ele == '}') {
                if (stk.empty() || stk.top() != '{') return false;
                stk.pop();
            } else if (ele == ']') {
                if (stk.empty() || stk.top() != '[') return false;
                stk.pop();
            } else stk.push(ele);
        }
        return stk.empty();
    }
};

int main() {
    string s = "()[]{}";
    Solution obj;
    cout << obj.isValid(s) << endl;
    return 0;
}

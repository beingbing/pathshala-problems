#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stack;
        istringstream ss(path);
        string token;
        while(getline(ss, token, '/')) {
            if (token == "" || token == ".") continue;
            else if (token == "..") {
                if (!stack.empty()) stack.pop();
            } else stack.push(token);
        }
        string result;
        vector<string> vec;
        while (!stack.empty()) {
            vec.push_back(stack.top());
            stack.pop();
        }
        reverse(vec.begin(), vec.end());
        for (auto &ele : vec) result += "/" + ele;
        return result.length() > 0 ? result : "/" ;
    }
};

int main() {
    string path = "/home//foo/";
    Solution obj;
    cout << obj.simplifyPath(path) << endl;
    return 0;
}

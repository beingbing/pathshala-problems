#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
	public:
	string removeConsecutiveIdentical(string str) {
		stack<char> stk;
		for (auto &ele : str) {
			if (!stk.empty() && stk.top() == ele) stk.pop();
			else stk.push(ele);
		}
		string ans = "";
		while (!stk.empty()) ans += stk.top(), stk.pop();
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main() {
	string str;
	cin >> str;
	Solution obj;
	cout << obj.removeConsecutiveIdentical(str) << endl;
	return 0;
}

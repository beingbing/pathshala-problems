#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> freq(26,0);
    stack<char> stk;
    for (auto &ele : s) freq[ele - 'a']++;
    int cnt{0};
    string ans;
    for (auto &ele : s) {
        while (cnt < freq.size() && freq[cnt] == 0) cnt++;
        while (!stk.empty() && ((stk.top() - 'a') <= cnt)) {
            ans += stk.top();
            stk.pop();
        }
        freq[ele-'a']--;
        stk.push(ele);
    }
    while (!stk.empty()) ans += stk.top(), stk.pop();
    cout << ans << endl;
    return 0;
}

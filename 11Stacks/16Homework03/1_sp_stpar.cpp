#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) return 0;
        vector<int> nums(n, 0);
        for (int i{0}; i<n; i++) cin >> nums[i];
        stack<int> stk;
        int cnt{1};
        bool notPossible = false;
        for (auto ele : nums) {
             while (!stk.empty() && stk.top() == cnt) {
                stk.pop();
                cnt++;
            }
            if (ele == cnt) cnt++;
            else if (!stk.empty() && stk.top() < ele) {
                notPossible = true;
                break;
            } else stk.push(ele);
        }
        if (notPossible) cout << "no" << endl;
        else cout << "yes" << endl;
    }
    return 0;
}

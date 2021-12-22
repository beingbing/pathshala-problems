#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int> &a) {
        int m = 1e9 + 7, n = a.size();
        vector<int> nse(n), psoee(n);
        stack<int> s;
        s.push(0);
        for (int i{1}; i < n; i++) {
            while (!s.empty() && a[i] < a[s.top()]) {
                nse[s.top()] = i, s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            nse[s.top()] = n;
            s.pop();
        }
        s.push(n - 1);
        for (int i{n - 2}; i >= 0; i--) {
            while (!s.empty() && a[i] <= a[s.top()]) {
                psoee[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            psoee[s.top()] = -1;
            s.pop();
        }
        long long ans = 0, x;
        for (int i{0}; i < n; i++) {
            x = (long long) ((long long)(((i - psoee[i]) % m) * ((nse[i] - i) % m)) % m) * ((long long)(a[i] % m) % m);
            ans = (long long) (ans % m + x % m) % m;
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {11, 81, 94, 43, 3};
    Solution obj;
    cout << obj.sumSubarrayMins(arr) << endl;
    return 0;
}

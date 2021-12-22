#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ht(n, 0);
    for (int i{0}; i<n; i++) cin >> ht[i];
    vector<int> nse(n), pse(n);
    stack<int> s;
    s.push(0);
    for (int i{0}; i<n; i++) {
        while (!s.empty() && ht[i] < ht[s.top()]) {
            nse[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        nse[s.top()] = n;
        s.pop();
    }
    s.push(n-1);
    for (int i{n-2}; i>=0; i--) {
        while (!s.empty() && ht[i] < ht[s.top()]) {
            pse[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        pse[s.top()] = -1;
        s.pop();
    }
    vector<int> ans(n+1,0);
    int len;
    for (int i{0}; i<n; i++) {
        len = nse[i] - pse[i] - 1;
        ans[len] = max(ans[len], ht[i]);
    }
    for (int i{n-1}; i>=0; i--) ans[i] = max(ans[i], ans[i+1]);
    for (int i{1}; i<=n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}

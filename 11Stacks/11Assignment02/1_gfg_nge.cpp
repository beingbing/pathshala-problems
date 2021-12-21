#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> nextLargerElement(vector<long long> a, int n) {
        stack<long long> s;
        s.push(0);
        vector<long long> ans(n);
        for (long long i{1}; i<n; i++) {
            while (!s.empty() && a[i] > a[s.top()]) {
                ans[s.top()] = a[i];
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            ans[s.top()] = -1;
            s.pop();
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

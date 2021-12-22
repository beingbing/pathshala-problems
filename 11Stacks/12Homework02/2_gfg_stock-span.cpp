#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> calculateSpan(int price[], int n)
    {
        vector<int> pge(n, -1);
        stack<int> s;
        s.push(n-1);
        for (int i{n-2}; i>=0; i--) {
            while (!s.empty() && price[i] > price[s.top()]) {
                pge[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            pge[s.top()] = -1;
            s.pop();
        }
        for (int i{0}; i<n; i++) pge[i] = i - pge[i];
        return pge;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> s = obj.calculateSpan(a, n);
        for (i = 0; i < n; i++)
            cout << s[i] << " ";
        cout << endl;
    }
    return 0;
}

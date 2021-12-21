#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        int n = ht.size();
        if (n == 0) return 0;
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
        int maxArea = INT_MIN;
        for (int i{0}; i<n; i++) {
            maxArea = max(maxArea, ht[i]*(nse[i]-pse[i]-1));
        }
        return maxArea;
    }
};

int main() {
    vector<int> hts = {2,1,5,6,2,3};
    Solution obj;
    cout << obj.largestRectangleArea(hts) << endl;
    return 0;
}

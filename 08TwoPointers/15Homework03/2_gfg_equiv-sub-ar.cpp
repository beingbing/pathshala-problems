#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countDistinctSubarray(vector<int>& a, int n) {
        unordered_map<int, int> reqFreq, tempFreq;
        for (int i{0}; i < n; i++) reqFreq.insert({a[i], 1});
        int distChars = reqFreq.size();
        if (distChars == n) return 1;
        int c = 0, start = 0, total{0};
        for (int end{0}; end < n; end++) {
            tempFreq[a[end]]++;
            if (tempFreq[a[end]] == reqFreq[a[end]]) c++;
            while (c == distChars) {
                total += n - end;
                c -= (tempFreq[a[start]] > reqFreq[a[start]]) ? 0 : 1;
                tempFreq[a[start]]--;
                start++;
            }
        }
        return total;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        Solution ob;
        cout << ob.countDistinctSubarray(a, n) << endl;
    }
    return 0;
}

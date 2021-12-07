#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& a, int distChars) {
        int n = a.size();
        if (distChars == n) return 1;
        unordered_map<int, int> tempFreq;
        int c = 0, start = 0, total{0};
        for (int end{0}; end < n; end++) {
            tempFreq[a[end]]++;
            if (tempFreq[a[end]] == 1) c++;
            while (c == distChars) {
                int sudoN = end;
                while(sudoN < n-1 && tempFreq[a[sudoN+1]] > 0) sudoN++;
                total += sudoN - end + 1;
                c -= (tempFreq[a[start]] > 1) ? 0 : 1;
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
        int k;
        cin >> k;
        Solution ob;
        cout << ob.subarraysWithKDistinct(a, k) << endl;
    }
    return 0;
}

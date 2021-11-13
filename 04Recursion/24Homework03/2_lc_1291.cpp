// samar try it with sliding window technique, that would be fun to implement on this problem

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = to_string(low);
        int n = str.size();
        string tmp = "";
        int i;
        for (i = 1; i<=n; i++) tmp += to_string(i);
        while (i < 10 && stoll(tmp) < low) {
            tmp.erase(tmp.begin());
            tmp += to_string(i);
            i++;
        }
        vector<int> ans;
        if (low <= stoll(tmp) && stoll(tmp) <= high) ans.push_back(stoll(tmp));
        int lim = to_string(high).size();
        while (n <= lim) {
            while (i < 10) {
                tmp.erase(tmp.begin());
                tmp += to_string(i);
                if (low <= stoll(tmp) && stoll(tmp) <= high) ans.push_back(stoll(tmp));
                else break;
                i++;
            }
            n++;
            tmp = "";
            for (i = 1; i<=n; i++) tmp += to_string(i);
            if (low <= stoll(tmp) && stoll(tmp) <= high) ans.push_back(stoll(tmp));
        }
        return ans;
    }
};

int main() {
    Solution* obj = new Solution();
    vector<int> ans = obj->sequentialDigits(1000, 13000);
    for (auto ele : ans) cout << ele << endl;
    return 0;
}

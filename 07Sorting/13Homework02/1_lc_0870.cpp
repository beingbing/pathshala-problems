#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int> &a, vector<int> &b) {
        int n = a.size();
        multiset<int> s(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            auto p = *s.rbegin() <= b[i] ? s.begin() : s.upper_bound(b[i]);
            a[i] = *p;
            s.erase(p);
        }
        return a;
    }
};

int main() {
    vector<int> nums1 = {2, 7, 11, 15}, nums2 = {1, 10, 4, 11};
    Solution obj;
    auto ans = obj.advantageCount(nums1, nums2);
    for (auto ele : ans) cout << ele << '\t';
    cout << endl;
    return 0;
}

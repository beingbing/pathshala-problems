#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& a1, vector<int>& a2) {
        vector<int> ans;
        int i{0}, j{0}, n = a1.size(), m = a2.size();
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        while (i < n && j < m) {
            cout << i << " " << a1[i] << " " << j << " " << a2[j] << endl;
            if (a1[i] < a2[j]) i++;
            else if (a1[i] > a2[j]) j++;
            else {
                if (ans.empty()) ans.push_back(a1[i]);
                else if (ans.back() != a1[i]) ans.push_back(a1[i]);
                i++, j++;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums1 = {4,9,5}, nums2 = {9,4,9,8,4};
    Solution obj;
    vector<int> ans = obj.intersection(nums1, nums2);
    for (auto ele : ans) cout << ele << '\t';
    cout << endl;
    return 0;
}
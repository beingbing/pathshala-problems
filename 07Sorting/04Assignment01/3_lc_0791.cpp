#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> rank(26, 26);
        for (int i{0}; i<order.size(); i++) rank[order[i]-'a'] = i;
        vector<pair<char, int>> str;
        for (auto ele : s) str.push_back({ele, rank[ele-'a']});
        sort(str.begin(), str.end(), [](pair<char, int> x, pair<char, int> y) {
            return x.second < y.second;
        });
        string ans;
        for (auto ele : str) ans += ele.first;
        return ans;
    }
};

int main() {
    string order = "cba", s = "abcd";
    Solution obj;
    cout << obj.customSortString(order, s) << endl;
    return 0;
}
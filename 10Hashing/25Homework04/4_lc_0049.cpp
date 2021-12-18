#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        if (strs.size() == 0) return vector<vector<string>>();
        int n = strs.size();
        string word;
        unordered_map<string, vector<string>> mp;
        for (int i{0}; i < n; i++) {
            word = strs[i];
            sort(word.begin(), word.end());
            if (mp.find(word) == mp.end()) mp.insert({word, {strs[i]}});
            else mp[word].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto ele : mp) ans.push_back(ele.second);
        return ans;
    }
};

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution obj;
    vector<vector<string>> ans = obj.groupAnagrams(strs);
    for (auto &rw : ans) {
        for (auto &ele : rw)
            cout << ele << " ";
        cout << endl;
    }
    return 0;
}

// it will give TLE, try it with trie
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    bool isPal(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> ump;
        for (int i{0}; i < words.size(); i++)
            ump[string(words[i].rbegin(), words[i].rend())] = i;
        map<pair<int, int>, bool> m;
        vector<vector<int>> ans;
        for (int i{0}; i < words.size(); i++) {
            if (ump.find("") != ump.end() && ump[""] != i && isPal(words[i], 0, words[i].size() - 1) && m.find({i, ump[""]}) == m.end())
                m[{i, ump[""]}] = true, m[{ump[""], i}] = true, ans.push_back({i, ump[""]}), ans.push_back({ump[""], i});
            string prefix;
            for (int j{0}; j < words[i].size(); j++) {
                prefix = words[i].substr(0, j + 1);
                if (ump.find(prefix) != ump.end() && ump[prefix] != i && isPal(words[i], j + 1, words[i].size() - 1) && m.find({i, ump[prefix]}) == m.end())
                    m[{i, ump[prefix]}] = true, ans.push_back({i, ump[prefix]});
            }
            string suffix;
            for (int j = words[i].size() - 1; j >= 0; j--) {
                suffix = words[i].substr(j, words[i].size() - j);
                if (ump.find(suffix) != ump.end() && ump[suffix] != i && isPal(words[i], 0, j - 1) && m.find({ump[suffix], i}) == m.end())
                    m[{ump[suffix], i}] = true, ans.push_back({ump[suffix], i});
            }
        }
        return ans;
    }
};

int main() {
    vector<string> words = {"abcd","dcba","lls","s","sssll"};
    Solution obj;
    vector<vector<int>> ans = obj.palindromePairs(words);
    for (auto &row : ans) {
        for (auto ele : row) cout << ele << " ";
        cout << endl;
    }
    return 0;
}

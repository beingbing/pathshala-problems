#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> ans;
        if (s.size() == 0 || words.size() == 0 || words.size() * words[0].size() > s.size()) return ans;
        unordered_map<string, int> wordsFreq, tmp;
        for (auto &word : words) wordsFreq[word]++;
        int n = words.size(), l = words[0].size();
        for (int i{0}; i <= s.size() - n * l; i++) {
            for (int j = i; j < i + n * l; j += l)
                tmp[s.substr(j, l)]++;
            bool flag = true;
            for (int j{0}; j < n; j++)
                if (tmp.find(words[j]) == tmp.end() || tmp[words[j]] != wordsFreq[words[j]]) {
                    flag = false;
                    break;
                }
            if (flag)
                ans.push_back(i);
            tmp.clear();
        }
        return ans;
    }
};

int main() {
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};
    Solution obj;
    vector<int> ans = obj.findSubstring(s, words);
    for (auto ele : ans) cout << ele << endl;
    return 0;
}

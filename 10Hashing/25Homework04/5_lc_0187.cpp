#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> seen, repeated;
        string str;
        for (int i{0}; i+9 < s.length(); i++) {
            str = s.substr(i,10);
            if (seen.find(str) != seen.end()) {
                repeated.insert(str);
            }
            seen.insert(str);
        }
        return vector<string>(repeated.begin(), repeated.end());
    }
};

int main() {
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution obj;
    vector<string> ans = obj.findRepeatedDnaSequences(s);
    for (auto ele : ans) cout << ele << endl;
    return 0;
}

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
    
    vector<string> res;
    
    void permute(string str, int idx) {
        if (idx == str.size()) {
            res.push_back(str);
            return;
        }
        vector<int> freq(26,0);
        for (auto toSwapIdx{idx}; toSwapIdx < str.size(); toSwapIdx++) {
            if (freq[str[toSwapIdx]-'A'] == 0) {
                swap(str[idx], str[toSwapIdx]); // do
                permute(str, idx+1);            // recurse
                swap(str[idx], str[toSwapIdx]); // undo
                freq[str[toSwapIdx]-'A']++;
            }
        }
    }
    
public:
    int numTilePossibilities(string tiles) {
        for (int i{0}; i < tiles.size(); i++) {
            for (int len{1}; len <= tiles.size(); len++) {
                string str = tiles.substr(i, len);
                auto it = find(res.begin(), res.end(), str);
                if (it == res.end()) permute(str, 0);
            }
        }
        // for (auto ele : res) cout << ele << endl;
        return res.size();
    }
};
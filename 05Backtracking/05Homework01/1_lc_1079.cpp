#include <vector>
#include <string>
using namespace std;

class Solution {
    
    int ans{0};
    
    void permute(string str, int idx) {
        if (idx == str.size()) return;
        vector<int> freq(26,0);
        for (auto toSwapIdx{idx}; toSwapIdx < str.size(); toSwapIdx++) {
            if (freq[str[toSwapIdx]-'A'] == 0) {
                freq[str[toSwapIdx]-'A']++;
                swap(str[idx], str[toSwapIdx]);
                ans++;
                permute(str, idx+1);
                swap(str[idx], str[toSwapIdx]);
            }
        }
    }
    
public:
    int numTilePossibilities(string tiles) {
        permute(tiles, 0);
        return ans;
    }
};
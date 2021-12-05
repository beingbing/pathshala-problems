#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, n = s.size();
        if (n == 0) return 0;
        vector<int> freq(256, 0);
        freq[s[0]]++;
        int len = 1;
        while (j < n-1) {
            if (freq[s[j+1]] == 0) {
                freq[s[j+1]]++;
                j++;
            } else {
                freq[s[i]]--;
                i++;
            }
            len = max(len, j-i+1);
        }
        return len;
    }
};

int main() {
    string s = "abcabcbb";
    Solution obj;
    cout << obj.lengthOfLongestSubstring(s) << endl;
    return 0;
}

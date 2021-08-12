#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int freq = 0;
        for (int i{0}; i<k; i++) if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') freq++;
        int maxCnt{0}, n = s.size();
        for (int i{k}; i < n; i++) {
            if (freq > maxCnt) maxCnt = freq;
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') freq++;
            if (s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u') freq--;
        }
        if (freq > maxCnt) maxCnt = freq;
        return maxCnt;
    }
};

int main() {
    Solution* obj = new Solution();
    int ans = obj->maxVowels("abciiidef", 3);
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() == 0) return "";
        vector<int> freqS(256, 0), freqT(256, 0);
        int distChars{0};
        for (int i{0}; i<t.size(); i++) {
            if (freqT[t[i]] == 0) distChars++;
            freqT[t[i]]++;
        }
        int c = 0, start = 0, end;
        for (int i{0}; i<s.size(); i++) {
            freqS[s[i]]++;
            if (freqS[s[i]] == freqT[s[i]]) c++;
            if (c == distChars) {end = i; break;}
        }
        if (c < distChars) return "";
        int anss = start, anse = end, minm = end-start+1;
        while (end < s.size()) {
            while (freqS[s[start]] > freqT[s[start]]) freqS[s[start]]--, start++;
            if (end-start+1 < minm) {
                minm = end-start+1;
                anss = start;
                anse = end;
            }
            end++;
            if (end < s.size()) freqS[s[end]]++;
        }
        return s.substr(anss, minm);
    }
};

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    Solution obj;
    cout << obj.minWindow(s, t) << endl;
    return 0;
}

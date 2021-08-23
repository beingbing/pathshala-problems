#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1chars(26), s2chars(26);
        for (auto alps : s1) s1chars[alps-'a']++;
        int k = s1.size(), n = s2.size();
        for (int i{0}; i<k; i++) s2chars[s2[i]-'a']++;
        for (int i{k}; i<n; i++) {
            if (s1chars == s2chars) return true;
            s2chars[s2[i]-'a']++;
            s2chars[s2[i-k]-'a']--;
        }
        if (s1chars == s2chars) return true;
        return false;
    }
};

int main() {
    Solution* obj = new Solution();
    cout << obj->checkInclusion("ab", "eidbaooo") << endl;
    return 0;
}
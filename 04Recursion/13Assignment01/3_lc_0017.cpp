#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    vector<string> ans;
    string phoneDigits;
    
    vector<char> getChars(char c) {
        switch (c) {
          case '1':
            return vector<char>{};
          case '2':
            return vector<char>{'a','b','c'};
          case '3':
            return vector<char>{'d','e','f'};
          case '4':
            return vector<char>{'g','h','i'};
          case '5':
            return vector<char>{'j','k','l'};
          case '6':
            return vector<char>{'m','n','o'};
          case '7':
            return vector<char>{'p','q','r','s'};
          case '8':
            return vector<char>{'t','u','v'};
          case '9':
            return vector<char>{'w','x','y','z'};
        }
        return vector<char>{};
    }
    
    void createCombinations(string temp, vector<char> cand, int i) {
        if (temp.size() == phoneDigits.size()) {ans.push_back(temp);return;}
        for (int j{0}; j<cand.size(); j++)
            createCombinations(temp+cand[j], getChars(phoneDigits[i+1]), i+1);
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return ans;
        phoneDigits = digits;
        createCombinations("", getChars(digits[0]), 0);
        return ans;
    }
};

int main() {
    string digits = "47";
    Solution obj;
    vector<string> ans = obj.letterCombinations(digits);
    for (auto &ele : ans) cout << ele << endl;
    return 0;
}

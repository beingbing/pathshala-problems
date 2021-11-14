#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> ans;

bool isPalindrome(string s) {
    string r = s;
    reverse(r.begin(), r.end());
    return r == s;
}

void partition(string str, vector<string>& cand, int idx) {
    if (idx == str.size()) {
        ans.push_back(cand);
        return;
    }

    for (auto toSwapIdx{idx}; toSwapIdx < str.size(); toSwapIdx++) {
        if (isPalindrome(str.substr(idx, toSwapIdx-idx+1))) {
            cand.push_back(str.substr(idx, toSwapIdx-idx+1));
            partition(str, cand, toSwapIdx+1);
            cand.pop_back();
        }
    }
}

int main() {
    string str = "aab";
    vector<string> cand;
    partition(str, cand, 0);
    for (auto lst : ans) {
        cout << "$: ";
        for (auto ele : lst) cout << ele << '\t';
        cout << endl;
    }
    return 0;
}

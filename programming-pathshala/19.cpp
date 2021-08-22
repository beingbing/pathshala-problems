// write all the permutations of a given string
// all characters are distinct
#include <iostream>
#include <vector>
using namespace std;


void permute(string str, int idx) {
    if (idx == str.size()) {
        cout << str << endl;
        return;
    }
    vector<int> freq(26,0);
    for (auto toSwapIdx{idx}; toSwapIdx < str.size(); toSwapIdx++) {
        if (freq[str[toSwapIdx]-'a'] == 0) {
            swap(str[idx], str[toSwapIdx]);
            permute(str, idx+1);
            swap(str[idx], str[toSwapIdx]);
            freq[str[toSwapIdx]-'a']++;
        }
    }
}

int main() {
    string str = "aba";
    permute(str, 0);
    return 0;
}
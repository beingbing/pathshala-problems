// write all the permutations of a given string
// all characters are not distinct

/*

total number of strings that can be generated will be
    !len / (!freq(a)*!freq(b)*...)

*/

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
        if (freq[str[toSwapIdx]-'a'] == 0) {// if i have seen the characters for first time then proceed
            swap(str[idx], str[toSwapIdx]); // do
            permute(str, idx+1);            // recurse
            swap(str[idx], str[toSwapIdx]); // undo
            freq[str[toSwapIdx]-'a']++;
        }
    }
}

int main() {
    string str = "aba";
    permute(str, 0);
    return 0;
}
/*

~~ permutations of a string -1 ~~

Given a string s with all distinct characters, print all it's permutations.

for a string s of size N with all distinct characters will have !N permutations.

TC = O(n^(n+1))

*/
// write all the permutations of a given string

#include <iostream>
using namespace std;

void permute(string str, int idx) {
    if (idx == str.size()) {
        cout << str << endl;
        return;
    }
    for (auto toSwapIdx{idx}; toSwapIdx < str.size(); toSwapIdx++) {
        swap(str[idx], str[toSwapIdx]); // do, make changes
        permute(str, idx+1);            // check what you want, make progress
        swap(str[idx], str[toSwapIdx]); // undo changes while returning
    }
}

int main() {
    string str = "abc";
    permute(str, 0);
    return 0;
}
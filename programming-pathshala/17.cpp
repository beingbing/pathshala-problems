// write all the permutations of a given string
#include <iostream>
using namespace std;

void permute(string str, int idx) {
    if (idx == str.size()) {
        cout << str << endl;
        return;
    }
    for (auto toSwapIdx{idx}; toSwapIdx < str.size(); toSwapIdx++) {
        swap(str[idx], str[toSwapIdx]);
        permute(str, idx+1);
        swap(str[idx], str[toSwapIdx]);
    }
}

int main() {
    string str = "abc";
    permute(str, 0);
    return 0;
}
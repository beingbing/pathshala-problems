// write all the permutations of a given string in lexicographic order

#include <iostream>
using namespace std;

void rightRotate(string& str, int i, int j) {
    int temp = str[j];
    for (auto idx{j}; idx > i; idx--) str[idx] = str[idx-1];
    str[i] = temp;
}

void leftRotate(string& str, int i, int j) {
    int temp = str[i];
    for (auto idx{i}; idx < j; idx++) str[idx] = str[idx+1];
    str[j] = temp;
}

void permute(string str, int idx) {
    if (idx == str.size()) {
        cout << str << endl;
        return;
    }
    for (auto toSwapIdx{idx}; toSwapIdx < str.size(); toSwapIdx++) {
        rightRotate(str, idx, toSwapIdx); // do
        permute(str, idx+1);              // recurse  
        leftRotate(str, idx, toSwapIdx);  // undo
    }
}

int main() {
    string str = "abc";
    permute(str, 0);
    return 0;
}
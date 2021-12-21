#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    for (auto &c : s) {
        if (!st.empty() && st.top() == c) st.pop();
        else st.push(c);
    }
    if (st.empty()) cout << "Yes" << endl;
    else cout << "No" << endl; 
    return 0;
}

// reversing a stack using recursion, without using any other DS
#include <iostream>
#include <stack>
using namespace std;


void insertAtBottom(stack<char>& st, char x) {
    if (st.empty()) st.push(x);
    else {
        char a = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(a);
    }
}

void reverse(stack<char>& st) {
    if (!st.empty()) {
        char x = st.top();
        st.pop();
        reverse(st);
        insertAtBottom(st, x);
    }
}

int main() {
    stack<char> st;
    string ns;
    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');
    cout << "Original Stack" << endl;
    cout << "1" << " " << "2" << " " << "3" << " " << "4" << endl;

    reverse(st);

    cout << "Reversed Stack" << endl;
    while (!st.empty()) {
        char p = st.top();
        st.pop();
        ns += p;
    }
    cout << ns[3] << " " << ns[2] << " " << ns[1] << " " << ns[0] << endl;
    return 0;
}

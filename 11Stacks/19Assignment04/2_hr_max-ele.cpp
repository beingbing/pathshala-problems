#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

class MaxStack {
    stack<pair<int, int>> s;

public:
    MaxStack() {}

    void push(int x) {
        if (s.empty()) s.push({x, x});
        else {
            int minm = max(x, s.top().second);
            s.push({x, minm});
        }
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMax() {
        return s.top().second;
    }
};

vector<int> getMax(vector<string> operations) {
    vector<int> ans;
    MaxStack obj;
    for (auto &ops : operations) {
        stringstream ss(ops);
        istream_iterator<string> begin(ss);
        istream_iterator<string> end;
        vector<string> vstrings(begin, end);
        if (vstrings[0] == "1") obj.push(stoi(vstrings[1]));
        else if (vstrings[0] == "2") obj.pop();
        else ans.push_back(obj.getMax());

    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<string> operations;
    string str;
    getline(cin, str);
    for (int i{0}; i<n; i++) {
        getline(cin, str);
        operations.push_back(str);
    }
    vector<int> ans = getMax(operations);
    for (auto &ele : ans) cout << ele << endl;
    return 0;
}

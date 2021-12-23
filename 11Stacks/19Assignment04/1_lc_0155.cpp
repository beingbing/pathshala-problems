#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class MinStack {
    stack<pair<int, int>> s;

public:
    MinStack() {}

    void push(int x) {
        if (s.empty()) s.push({x, x});
        else {
            int minm = min(x, s.top().second);
            s.push({x, minm});
        }
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
    }
};

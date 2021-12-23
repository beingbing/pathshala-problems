#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class MinStack {
    stack<long> s;
    long curMin;

public:
    MinStack() {
        curMin = LONG_MAX;
    }
    
    void push(long x) {
        if (s.empty()) {
            s.push(x);
            curMin = x;
            return;
        }
        if (x < curMin) {
            s.push((long)2 * x - curMin);
            curMin = x;
        } else s.push(x);
    }

    void pop() {
        if (s.top() < curMin) {
            curMin = (long)2 * curMin - s.top();
            s.pop();
        } else s.pop();
    }

    int top() {
        if (s.top() < curMin) return curMin;
        return s.top();
    }

    int getMin() {
        return curMin;
    }
};

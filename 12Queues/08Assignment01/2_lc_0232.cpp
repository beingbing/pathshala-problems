#include <stack>
using namespace std;

class MyQueue {
    stack<int> input, output;

public:
    MyQueue() {}
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int x = peek();
        output.pop();
        return x;
    }
    
    int peek() {
        if (output.empty())
            while(input.size())
                output.push(input.top()), input.pop();
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

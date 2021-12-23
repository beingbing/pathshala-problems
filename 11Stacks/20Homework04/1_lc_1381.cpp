#include <vector>
using namespace std;

class CustomStack {
    vector<int> stk;
    int mxSz;
public:
    CustomStack(int maxSize) {
        mxSz = maxSize;
    }
    
    void push(int x) {
        if (stk.size() < mxSz) stk.push_back(x);
    }
    
    int pop() {
        if (stk.size() > 0) {
            int ans = stk.back();
            stk.pop_back();
            return ans;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int n = min(k, (int)stk.size());
        for (int i{0}; i<n; i++) stk[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    stack<NestedInteger> s;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) s.push(nestedList[i]);
    }

    int next() {
        int ans = s.top().getInteger();
        s.pop();
        return ans;
    }

    bool hasNext() {
        while(!s.empty()) {
            if(s.top().isInteger()) return true;
            NestedInteger cur = s.top();
            s.pop();
            const vector<NestedInteger> &list = cur.getList();
            for(int i = list.size() - 1; i >= 0; i--) s.push(list[i]);
            
        }
        return false;
    }
};

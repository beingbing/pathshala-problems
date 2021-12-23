#include <stack>
#include <unordered_map>
using namespace std;

class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int maxfreq;

public:
    FreqStack() {
        maxfreq = 0;
    }

    void push(int x) {
        maxfreq = max(maxfreq, ++freq[x]);
        group[freq[x]].push(x);
    }

    int pop() {
        int x = group[maxfreq].top();
        group[maxfreq].pop();
        if (group[freq[x]].size() == 0) maxfreq--;
        freq[x]--;
        return x;
    }
};

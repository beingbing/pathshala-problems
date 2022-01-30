#include <queue>
using namespace std;

class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double curMedian;

    void updateMedian() {
        if (maxHeap.size() == minHeap.size()) curMedian = (maxHeap.top() + minHeap.top())/2.0;
        else if (maxHeap.size() > minHeap.size()) curMedian = maxHeap.top();
        else curMedian = minHeap.top();
    }

    void addToMaxHeap(int num) {
        if (maxHeap.size() <= minHeap.size()) maxHeap.push(num);
        else {
            int x = maxHeap.top();
            maxHeap.pop();
            minHeap.push(x);
            maxHeap.push(num);
        }
    }

    void addToMinHeap(int num) {
        if (maxHeap.size() >= minHeap.size()) minHeap.push(num);
        else {
            int x = minHeap.top();
            minHeap.pop();
            maxHeap.push(x);
            minHeap.push(num);
        }
    }

public:
    MedianFinder() {
        curMedian = 0.0;
    }
    
    void addNum(int num) {
        if (num <= curMedian) addToMaxHeap(num);
        else addToMinHeap(num);
        updateMedian();
    }
    
    double findMedian() {
        return curMedian;
    }
};

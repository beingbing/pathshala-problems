#include <queue>
using namespace std;

class MyCircularQueue {
    
    vector<int> data;
    int head, tail, cnt, sz;
    
public:
    MyCircularQueue(int k) {
        data.resize(k);
        head = 0;
        tail = 0;
        cnt = 0;
        sz = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        data[tail] = value;
        tail = (tail + 1) % sz;
        cnt++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % sz;
        cnt--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return data[(tail + sz - 1) % sz]; // -1 because rear is pointing to next empty cell
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == sz;
    }
};

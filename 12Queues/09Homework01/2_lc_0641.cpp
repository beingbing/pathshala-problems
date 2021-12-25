#include <vector>
using namespace std;

class MyCircularDeque {
    
    vector<int> buffer;
    int cnt;
    int sz;
    int front;
    int rear;
    
public:
    MyCircularDeque(int k): buffer(k, 0), cnt(0), sz(k), front(k - 1), rear(0) {}
    
    bool insertFront(int value) {
        if (isFull()) return false;
        buffer[front] = value;
        front = (front - 1 + sz) % sz;
        ++cnt;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        buffer[rear] = value;
        rear = (rear + 1) % sz;
        ++cnt;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % sz;
        --cnt;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + sz) % sz;
        --cnt;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return buffer[(front + 1) % sz];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return buffer[(rear - 1 + sz) % sz];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == sz;
    }
};

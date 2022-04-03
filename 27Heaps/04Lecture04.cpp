#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class MaxHeap {
    vector<int> a = {-1};
    int sz;

    void maxHeapify(int i) {
        if (i > sz / 2) return;
        int mx = i;
        if (a[2 * i] > a[mx]) mx = 2 * i;                               // change > to <, it will be a min-heap
        if (2 * i + 1 <= sz && a[2 * i + 1] > a[mx]) mx = 2 * i + 1;    // change > to <, it will be a min-heap
        if (mx != i) swap(a[i], a[mx]), maxHeapify(mx);
    }

    void buildMaxHeap(int n) {
        for (int i{n/2}; i>=1; i--) maxHeapify(i);
    }

public:

    MaxHeap(vector<int> ar) {
        for (int i{0}; i<ar.size(); i++) a.push_back(ar[i]);
        sz = ar.size();
        buildMaxHeap(sz);
    }

    int getMax() {
        return a[1];
    }

    void insert(int x) {
        a.push_back(x);
        sz++;
        int i = sz;
        while (i > 1 && a[i] > a[i / 2]) {
            swap(a[i], a[i / 2]);
            i = i / 2;
        }
    }

    int deleteRoot() {
        int x = a[1];
        swap(a[1], a[sz]);
        sz--;
        a.pop_back();
        maxHeapify(1);
        return x;
    }

    int deleteAtIndex(int i) {
        int x = a[i];
        a[i] = INT_MAX;
        maxHeapify(1);
        deleteRoot();
        return x;
    }
};

int main() {
    vector<int> vec = {6, 3, 5, 7, 9, 4, 2, 8};
    MaxHeap* mxH = new MaxHeap(vec);
    cout << mxH->getMax() << endl;
    mxH->insert(12);
    mxH->deleteAtIndex(2);
    cout << mxH->getMax() << endl;
    mxH->deleteRoot();
    cout << mxH->getMax() << endl;
}

#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int>& a, int& n, int i) {
    if (i >= n/2) return;
    int mx = i;
    int l = 2 * i + 1;
    if (a[l] > a[mx]) mx = l;
    int r = 2 * i + 2;
    if (r < n && a[r] > a[mx]) mx = r;
    if (mx != i) {
        swap(a[i], a[mx]);
        maxHeapify(a, n, mx);
    }
}

void buildMaxHeap(vector<int>& a, int& n) {
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--) maxHeapify(a, n, i);
}

void printHeap(vector<int>& a, int& n) {
    cout << "Array representation of Heap is:" << endl;
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << endl;
}

int main() {
    vector<int> a = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = 11;
    buildMaxHeap(a, n);
    printHeap(a, n);
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> a = {-1};
    int sz;
    
    int deleteRoot() {
        int x = a[1];
        swap(a[1], a[sz]);
        sz--;
        a.pop_back();
        heapify(1);
        return x;
    }
    
public:
    void heapify(int i) {
        if (i > sz / 2) return;
        int mn = i;
        if (a[2 * i] < a[mn]) mn = 2 * i;
        if (2 * i + 1 <= sz && a[2 * i + 1] < a[mn]) mn = 2 * i + 1;
        if (mn != i) swap(a[i], a[mn]), heapify(mn);
    }

public:
    void buildHeap(int n) { 
        for (int i{n/2}; i>=1; i--) heapify(i);
    }

public:
    void heapSort(int ar[], int n) {
        for (int i{0}; i<n; i++) a.push_back(ar[i]);
        sz = n;
        buildHeap(sz);
        for (int i{0}; i<n; i++) {
            ar[i] = a[1];
            deleteRoot();
        }
    }
};

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[1000000], n, T, i;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) scanf("%d", &arr[i]);
        Solution ob;
        ob.heapSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}

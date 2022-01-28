#include <iostream>
using namespace std;

class Solution {

    void deleteRoot(int a[], int& sz) {
        swap(a[0], a[sz-1]);
        sz--;
        heapify(a, sz, 0);
    }

public:
    void heapify(int a[], int n, int i) {
        if (i >= n/2) return;
        int mn = i;
        int l = 2 * i + 1;
        if (a[l] < a[mn]) mn = l;
        int r = 2 * i + 2;
        if (r < n && a[r] < a[mn]) mn = r;
        if (mn != i) {
            swap(a[i], a[mn]);
            heapify(a, n, mn);
        }
    }

public:
    void buildHeap(int a[], int n) {
        int startIdx = (n / 2) - 1;
        for (int i = startIdx; i >= 0; i--) heapify(a, n, i);
    }

public:
    void heapSort(int arr[], int n) {
        int a[n];
        for (int i{0}; i<n; i++) a[i] = arr[i];
        buildHeap(a, n);
        int sz = n;
        for (int i{0}; i<n; i++) {
            arr[i] = a[0];
            deleteRoot(a, sz);
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

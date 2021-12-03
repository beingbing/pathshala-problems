#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>& a, int size) {
    int i;
    for (i = 0; i < size; i++) cout << a[i];
    cout << endl;
}

class Solution {

public:
    void quickSort(vector<int>& a, int low, int high) {
        if (low < high) {
            int q = partitionM1(a, low, high);
            quickSort(a, low, q - 1);
            quickSort(a, q + 1, high);
        }
    }

    int partitionM1(vector<int>& a, int low, int high) {
        int key = a[low], l = low + 1, r = high;
        while (l < r) {
            while (l <= high && a[l] <= key) l++;
            while (r >= low && a[r] > key) r--;
            if (l < r) swap(a[l], a[r]);
        }
        if (a[low] > a[r]) swap(a[low], a[r]);
        return r;
    }

    int partitionM2(vector<int>& a, int low, int high) {
        int x = a[high];
        int i = low-1;
        for (int j{low}; j<high; j++) {
            if (a[j] <= x) {
                i++;
                swap(a[i], a[j]);
            }
        }
        swap(a[i+1], a[high]);
        return i+1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        ob.quickSort(a, 0, n - 1);
        printArray(a, n);
    }
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void swapEle(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

public:
    void bubbleSort(vector<int>& a, int n) {
        for (int i{0}; i < n; i++) {
            bool done = false;
            while (!done) {
                done = true;
                int j = 0;
                while (j < n - i - 1) {
                    if (a[j] > a[j + 1]) {
                        swapEle(a[j], a[j + 1]);
                        done = true;
                    }
                    j++;
                }
            }
        }
    }
};

void printArray(vector<int>& arr, int size) {
    int i;
    for (i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n, t, i;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> arr(n, 0);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        ob.bubbleSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>& arr, int size) {
    int i;
    for (i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

class Solution {
public:
    void insertionSort(vector<int>& arr, int n) {
        for (int j{1}; j < n; j++) {
            int key = arr[j]; // swap 1st part
            int i = j - 1;    // inititalizing 2nd loop
            while (i >= 0 and arr[i] > key) { // 2nd loop conditions
                arr[i + 1] = arr[i]; // swap 2nd part
                i--;                 // loop decrement
            }
            arr[i + 1] = key; // swap 3rd part
        }
    }
};

int main() {
    int n, t, i;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> arr(n, 0);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        ob.insertionSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>& a, int& size) {
    int i;
    for (auto ele : a) cout << ele << " ";
    cout << endl;
}

class Solution {
public:
    void merge(vector<int>& a, int& s1, int& e1, int& e2) {
        int s2{e1+1};
        int i = s1, j = s2, c = s1;
        int tmp[e2];
        while (i <= e1 && j <= e2) {
            if (a[i] <= a[j]) tmp[c++] = a[i++];
            else tmp[c++] = a[j++];
        }
        while (i <= e1) tmp[c++] = a[i++];
        while (j <= e2) tmp[c++] = a[j++];
        for (i=s1; i<=e2; i++) a[i] = tmp[i];
    }

    void mergeSort(vector<int>& a, int l, int r) {
        if (l == r) return;
        int m = l + (r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
};

int main() {
    int n, t, i;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        ob.mergeSort(a, 0, n - 1);
        printArray(a, n);
    }
    return 0;
}

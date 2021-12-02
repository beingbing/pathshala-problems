#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int cnt{0};

    void merge(vector<int>& a, int& s1, int& e1, int& e2) {
        int s2{e1+1};
        int i = s1, j = s2, c = s1;
        for (; i<=e1; i++) {
            while (j <= e2 && a[i] > 2LL*a[j]) j++;
            cnt += j-s2;
        }
        i = s1, j = s2, c = s1;
        int tmp[e2];
        while (i <= e1 && j <= e2)
            if (a[i] <= a[j]) tmp[c++] = a[i++];
            else tmp[c++] = a[j++];
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

public:
    int reversePairs(vector<int>& ar) {
        int n = ar.size();
        mergeSort(ar, 0, n-1);
        return cnt;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        Solution obj;
        cout << obj.reversePairs(A) << endl;
    }
    return 0;
}

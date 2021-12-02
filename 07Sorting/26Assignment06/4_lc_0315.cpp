#include <iostream>
#include <vector>
using namespace std;

struct Element {
    int value, index, count;
};

class Solution {

    void merge(vector<Element>& a, int& s1, int& e1, int& e2) {
        int s2{e1+1};
        int i = s1, j = s2;
        for (; i<=e1; i++) {
            while (j <= e2 && a[i].value > a[j].value) j++;
            a[i].count += j-s2;
        }
        i = s1, j = s2;
        int c = s1;
        vector<Element> tmp(e2+1);
        while (i <= e1 && j <= e2) {
            if (a[i].value <= a[j].value) tmp[c++] = a[i++];
            else tmp[c++] = a[j++];
        }
        while (i <= e1) tmp[c++] = a[i++];
        while (j <= e2) tmp[c++] = a[j++];
        for (i=s1; i<=e2; i++) a[i] = tmp[i];
    }

    void mergeSort(vector<Element>& a, int l, int r) {
        if (l == r) return;
        int m = l + (r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<Element> a;
        for (int i{0}; i<n; i++) a.push_back({nums[i], i, 0});
        mergeSort(a, 0, nums.size()-1);
        vector<int> ans(n);
        for (auto ele : a) ans[ele.index] = ele.count;
        return ans;
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
        A = obj.countSmaller(A);
        for (auto ele : A) cout << ele << '\t';
        cout << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& a, vector<int> &b, vector<int> &c, int n1, int n2, int n3) {
    int i = 0, j = 0, k = 0, ans = INT_MAX;
    while (i < n1 && j < n2 && k < n3) {
        int val = max(a[i], max(b[j], c[k])) - min(a[i], min(b[j], c[k]));
        ans = min(val, ans);
        int minm = min(a[i], min(b[j], c[k]));
        if (a[i] == minm) i++;
        else if (b[j] == minm) j++;
        else k++;
    }
    return ans;
}

int main() {
    vector<int> D = {5, 8, 10, 15};
    vector<int> E = {6, 9, 15, 78, 89};
    vector<int> F = {2, 3, 6, 6, 8, 8, 10};
    cout << solve(D, E, F, 4, 5, 7) << endl;
    return 0;
}

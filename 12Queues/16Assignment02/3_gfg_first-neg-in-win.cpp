#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k);

int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) cin >> arr[i];
        long long int k;
        cin >> k;
        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long int k) {
    vector<long long int> ans;
    queue<long long int> q;
    for (int i{0}; i<k; i++) if (a[i] < 0) q.push(i);
    for (int i{k}; i<n; i++) {
        if (q.empty()) ans.push_back(0);
        else ans.push_back(a[q.front()]);
        if (!q.empty() && q.front() == i-k) q.pop();
        if (a[i] < 0) q.push(i);
    }
    if (q.empty()) ans.push_back(0);
    else ans.push_back(a[q.front()]);
    return ans;
}

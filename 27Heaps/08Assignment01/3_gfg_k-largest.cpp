#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> kLargest(int a[], int n, int k) {
        priority_queue<int> pq(a, a + n);
        int cnt = 0;
        vector<int> ans;
        while (cnt < k) {
            ans.push_back(pq.top());
            pq.pop();
            cnt++;
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}

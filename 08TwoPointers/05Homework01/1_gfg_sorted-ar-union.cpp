#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findUnion(int a1[], int a2[], int n, int m) {
        vector<int> ans;
        int i{0}, j{0};
        ans.push_back(min(a1[0], a2[0]));
        while (i < n && j < m) {
            if (a1[i] <= a2[j]) {
                if (ans.back() != a1[i]) ans.push_back(a1[i]);
                i++;
            } else {
                if (ans.back() != a2[j]) ans.push_back(a2[j]);
                j++;
            }
        }
        while (i < n) {
            if (ans.back() != a1[i]) ans.push_back(a1[i]);
            i++;
        }
        while (j < m) {
            if (ans.back() != a2[j]) ans.push_back(a2[j]);
            j++;
        }
        return ans;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        int arr1[N];
        int arr2[M];
        for (int i = 0; i < N; i++) cin >> arr1[i];
        for (int i = 0; i < M; i++) cin >> arr2[i];
        Solution ob;
        vector<int> ans = ob.findUnion(arr1, arr2, N, M);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

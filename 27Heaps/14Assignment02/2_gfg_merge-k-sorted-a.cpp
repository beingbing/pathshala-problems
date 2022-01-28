#include <iostream>
#include <queue>
#include <vector>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

vector<vector<int>> v;

struct Comp {
    bool operator() (pair<int, int>& a, pair<int, int>& b) {
        int val1 = v[a.first][a.second];
        int val2 = v[b.first][b.second];
        return val1 > val2;
    }
};

class Solution {
public:
    vector<int> mergeKArrays(vector<vector<int>> vec, int k) {
        v = vec;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
        for (int i{0}; i<k; i++) pq.push({i, 0});
        vector<int> ans;
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            int i = p.first, j = p.second;
            ans.push_back(vec[i][j]);
            pq.pop();
            if (j+1 < k) pq.push({i, j+1});
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<vector<int>> arr(N, vector<int>(N, 0));
        for (int i = 0; i < k; i++) for (int j = 0; j < k; j++) cin >> arr[i][j];
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}

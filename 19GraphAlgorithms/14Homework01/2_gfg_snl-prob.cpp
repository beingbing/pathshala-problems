#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minThrow(int N, int arr[]) {
        vector<int> diceRes = {+1, +2, +3, +4, +5, +6};
        vector<int> visited(31, 0);
        map<int, int> m;
        for (int i = 0; i + 1 < 2 * N; i += 2) m[arr[i]] = arr[i + 1];
        queue<pair<int, int>> q;
        visited[1] = 1;
        q.push({1, 0});
        while (!q.empty()) {
            int pos = q.front().first;
            int thrws = q.front().second;
            q.pop();
            if (pos == 30) return thrws;
            for (int i = 0; i < 6; i++) {
                int newPos = pos + diceRes[i];
                if (newPos >= 0 && newPos <= 30 && !visited[newPos]) {
                    if (m.find(newPos) != m.end()) {
                        visited[m[newPos]] = 1;
                        q.push({m[newPos], thrws + 1});
                    } else {
                        visited[newPos] = 1;
                        q.push({newPos, thrws + 1});
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[2 * N];
        for (int i = 0; i < 2 * N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.minThrow(N, arr) << "\n";
    }
    return 0;
}

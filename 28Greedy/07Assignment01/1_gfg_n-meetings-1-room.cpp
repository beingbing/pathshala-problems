#include <iostream>
#include <queue>
#include <vector>
using namespace std;


class Solution {

static bool Comp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

public:
    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int>> vec;
        for (int i{0}; i<n; i++) vec.push_back({start[i], end[i]});
        sort(vec.begin(), vec.end(), Comp);
        int ans = 1;
        int endTime = vec[0].second;
        for (int i{1}; i<n; i++) if (vec[i].first > endTime) ans++, endTime = vec[i].second;
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];
        for (int i = 0; i < n; i++) cin >> end[i];
        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}

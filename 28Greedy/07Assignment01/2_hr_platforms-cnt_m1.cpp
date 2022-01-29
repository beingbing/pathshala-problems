#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

bool Comp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    int n; 
    cin >> n;
    vector<pair<int, int>> schedule(n);
    for (int i{0}; i<n; i++) cin >> schedule[i].first >> schedule[i].second;
    sort(schedule.begin(), schedule.end(), Comp);
    vector<int> depTimes = {0};
    for (auto & train : schedule) {
        int closest = INT_MIN, platform = -1;
        for (int j{0}; j < (int)depTimes.size(); j++) {
            if (depTimes[j] <= train.first) {
                closest = max(closest, depTimes[j]);
                if (closest == depTimes[j]) platform = j;
            }
        }
        if (platform == -1) depTimes.push_back(train.second);
        else depTimes[platform] = train.second;
    }
    cout << depTimes.size() << endl;
    return 0;
}
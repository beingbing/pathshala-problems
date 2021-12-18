#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n, mod = 1e4;
    cin >> n;
    vector<pair<int,int>> points(n);
    unordered_map<int, int> xFreq, yFreq;
    for (int i{0}; i<n; i++) {
        cin >> points[i].first >> points[i].second;
        xFreq[points[i].first]++;
        yFreq[points[i].second]++;
    }
    int sameX, sameY, trianglesCnt{0};
    for (auto &point : points) {
        sameX = xFreq[point.first] - 1;
        sameY = yFreq[point.second] - 1;
        trianglesCnt += ((sameX%mod)*(sameY%mod)%mod);
    }
    cout << trianglesCnt%mod << endl;
    return 0;
}

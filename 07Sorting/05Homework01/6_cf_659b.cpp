#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int participants, regions;
    cin >> participants >> regions;
    vector<vector<pair<int, string>>> cands(regions);
    string surname;
    int region, points;
    for (int i{0}; i < participants; i++) {
        cin >> surname >> region >> points;
        cands[region - 1].push_back({points, surname});
    }
    for (auto &vec : cands) {
        sort(vec.begin(), vec.end(), [](pair<int, string> &x, pair<int, string> &y) { return x.first > y.first; });
        if (vec.size() > 2 && vec[1].first == vec[2].first) cout << "?\n";
        else cout << vec[0].second << " " << vec[1].second << '\n';
    }
    return 0;
}

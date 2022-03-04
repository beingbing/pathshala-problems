// codeforces problem link
// https://codeforces.com/problemset/problem/621/B
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> majorMap, minorMap;
    int n, x, y;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        majorMap[x-y]++;
        minorMap[x+y]++;
    }
    int ans{0};
    for (auto ele : majorMap) ans += (ele.second) * (ele.second-1) / 2;
    for (auto ele : minorMap) ans += (ele.second) * (ele.second-1) / 2;
    cout << ans << endl;
    return 0;
}
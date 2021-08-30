// codeforces problem link
// https://codeforces.com/problemset/problem/621/B
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> majorMap, minorMap;
    int n, x, y;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        if (majorMap.find(x-y) == majorMap.end()) majorMap.insert({x-y, 1});
        else majorMap[x-y]++;
        if (minorMap.find(x+y) == minorMap.end()) minorMap.insert({x+y, 1});
        else minorMap[x+y]++;
    }
    int ans{0};
    for (auto ele : majorMap) ans += (ele.second) * (ele.second-1) / 2;
    for (auto ele : minorMap) ans += (ele.second) * (ele.second-1) / 2;
    cout << ans << endl;
    return 0;
}
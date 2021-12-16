#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    int gcd(int val1, int val2) {
        if (val1 == 0) return val2;
        if (val2 == 0) return val1;
        int mx = max(val1, val2), mn = min(val1, val2);
        if (mx%mn == 0) return mn;
        return gcd(mx%mn, mn);
    }

    void standardise(int& numerator, int& denominator) {
        if (numerator == 0) denominator = 1;
        else if (denominator == 0) numerator = 1;
        else if ((numerator < 0 && denominator < 0) || denominator < 0)
            numerator *= -1, denominator *= -1;
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) return 0;
        int ans = 1;
        map<pair<int, int>, int> m;
        for (int i{0}; i<n; i++) {
            int olp = 0, maxm = 0;
            for (int j{i+1}; j<n; j++) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) olp++;
                else {
                    int xdiff = points[j][0] - points[i][0], ydiff = points[j][1] - points[i][1];
                    int g = gcd(abs(xdiff), abs(ydiff));
                    int f = xdiff/g, s = ydiff/g;
                    standardise(f, s);
                    m[{f,s}]++;
                    maxm = max(maxm, m[{f,s}]);
                }
            }
            ans = max(ans, 1+olp+maxm);
            m.clear();
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    Solution obj;
    cout << obj.maxPoints(points) << endl;
    return 0;
}

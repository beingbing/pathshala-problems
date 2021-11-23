#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        vector<pair<int, double>> vec;
        for (int i{0}; i<pos.size(); i++) vec.push_back({pos[i], (double)(target-pos[i]) / speed[i]});
        sort(vec.begin(), vec.end(), [](pair<int, double> x, pair<int, double> y) {return x.first > y.first;});
        double curSlowest{0};
        int fleets{0};
        for (auto ele : vec) if (ele.second > curSlowest) curSlowest = ele.second, fleets++;
        return fleets;
    }
};

int main() {
    vector<int> position = {10,8,0,5,3}, speed = {2,4,1,1,3};
    int target = 12;
    Solution obj;
    cout << obj.carFleet(target, position, speed) << endl;
    return 0;
}

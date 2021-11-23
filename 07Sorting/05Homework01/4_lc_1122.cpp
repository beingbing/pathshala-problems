#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> order(1001, 1000);
        for (int i{0}; i<arr2.size(); i++) order[arr2[i]] = i;
        sort(arr1.begin(), arr1.end(), [&](int x, int y) {
            if (order[x] == order[y]) return x < y;
            return order[x] < order[y];
        });
        return arr1;
    }
};

int main() {
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19}, arr2 = {2,1,4,3,9,6};
    Solution obj;
    vector<int> ans = obj.relativeSortArray(arr1, arr2);
    for (auto ele : ans) cout << ele << " ";
    cout << endl;
    return 0;
}

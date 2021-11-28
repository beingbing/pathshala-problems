#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        int n = a.size();
        if (n < 3) return 0;
        sort(a.begin(), a.end(), [](int &x, int &y) {return x > y;});
        for (int i{2}; i<n; i++)
            if (a[i-1]+a[i] > a[i-2])
                return a[i]+a[i-1]+a[i-2];
        return 0;
    }
};

int main() {
    vector<int> nums = {2,1,2};
    Solution obj;
    cout << obj.largestPerimeter(nums) << endl;
    return 0;
}

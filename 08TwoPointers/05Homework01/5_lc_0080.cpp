#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        if (a.size() == 0) return 0;
        int n = a.size(), i = 0, cnt{0};
        while (i < n) {
            if (cnt < 2 || a[i] > a[i-2]) {
                a[cnt] = a[i];
                cnt++;
            }
            i++;
        }
        return cnt;
    }
};

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution obj;
    cout << obj.removeDuplicates(nums) << endl;
    return 0;
}

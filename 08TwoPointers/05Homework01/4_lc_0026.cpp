#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        if (a.size() == 0) return 0;
        int slow = 0;
        for (int fast = 1; fast < a.size(); fast++)
            if (a[slow] != a[fast]) a[++slow] = a[fast];
        return slow+1;
    }
};

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution obj;
    cout << obj.removeDuplicates(nums) << endl;
    return 0;
}

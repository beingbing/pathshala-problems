#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& a, int val) {
        int i=0;
        int n = a.size();
        while(i<n) a[i]==val ? a[i] = a[--n] : i++;
        return n;
    }
};

int main() {
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    Solution obj;
    cout << obj.removeElement(nums, val) << endl;
    return 0;
}
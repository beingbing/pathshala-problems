#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n-1, j = m-1, i = n-1;
        
        while (i>=0 && j>=0)
            if (nums1[j] > nums2[i]) nums1[k--] = nums1[j--];
            else nums1[k--] = nums2[i--];
       
        while(i>=0) nums1[k--] = nums2[i--];
    }
};


int main() {
    vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};
    int m = 3, n = 3;
    Solution obj;
    obj.merge(nums1, m, nums2, n);
    for (auto ele : nums1) cout << ele << " ";
    cout << endl;
    return 0;
}

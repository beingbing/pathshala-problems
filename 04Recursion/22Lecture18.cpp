// count number of subsets whose sum equals target,
// all elements are positive and distinct
// and repetation in subset is allowed

#include <iostream>
#include <vector>
using namespace std;

int countSubSets(vector<int>& nums, int sum, int i) {
    if (sum < 0) return 0;
    if (sum == 0) return 1;
    if (i == nums.size()) return 0;
    return countSubSets(nums, sum-nums[i], i) + countSubSets(nums, sum, i+1);
}

int main() {
    vector<int> ar = {1,2};
    int ans = countSubSets(ar, 4, 0);
    cout << ans << endl;
    return 0;
}

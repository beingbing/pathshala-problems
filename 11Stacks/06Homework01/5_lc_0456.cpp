#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    bool find132pattern(vector<int> &nums) {
        int s3 = INT_MIN;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < s3) return true;
            else while (!st.empty() && nums[i] > st.top()) {
                    s3 = st.top();
                    st.pop();
                }
            st.push(nums[i]);
        }
        return false;
    }
};

int main() {
    vector<int> nums = {3, 1, 4, 2};
    Solution obj;
    cout << obj.find132pattern(nums) << endl;
    return 0;
}

// { Driver Code Starts
#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
class Solution {

    vector<vector<int>> subs;

    void subsets(vector<int> &nums, int i, vector<int> &sub) {
        subs.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub);
            sub.pop_back();
        }
    }

public:
    vector<int> subsetSums(vector<int> nums, int n) {
        sort(nums.begin(), nums.end());
        vector<int> sub;
        subsets(nums, 0, sub);
        for (auto st : subs) {
            int sum = 0;
            for (auto ele : st) sum += ele;
            sub.push_back(sum);
        }
        return sub;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

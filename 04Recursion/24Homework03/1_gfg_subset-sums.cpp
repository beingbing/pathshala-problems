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

import java.util.ArrayList;
import java.util.List;

public class SubsetSums {

    public List<Integer> subsetSums(int[] arr, int n) {
        List<Integer> result = new ArrayList<>();
        calculateSubsetSums(arr, 0, 0, result);
        return result;
    }

    private void calculateSubsetSums(int[] arr, int index, int currentSum, List<Integer> result) {
        if (index == arr.length) {
            result.add(currentSum);
            return;
        }

        // Include the current element in the sum
        calculateSubsetSums(arr, index + 1, currentSum + arr[index], result);

        // Exclude the current element from the sum
        calculateSubsetSums(arr, index + 1, currentSum, result);
    }

    public static void main(String[] args) {
        SubsetSums solver = new SubsetSums();
        int[] arr = {2, 3};
        System.out.println(solver.subsetSums(arr, arr.length)); // Expected output: [0, 2, 3, 5]

        int[] arr2 = {1, 2, 1};
        System.out.println(solver.subsetSums(arr2, arr2.length)); // Expected output: [0, 1, 1, 2, 2, 3, 3, 4]
    }
}

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size(), last{n-1}, frst{0};
        int val;
        while (frst <= last) {
            val = a[frst] + a[last];
            if (val > target) last--;
            else if (val < target) frst++;
            else if (val == target) return {frst+1, last+1};
        }
        return {};
    }
};

// two pointer method

import java.util.Scanner;

public class TwoSumSortedArray {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read size of the array
        int N = scanner.nextInt();
        int[] nums = new int[N];

        // Read the sorted array elements
        for (int i = 0; i < N; i++) {
            nums[i] = scanner.nextInt();
        }

        // Read the target value
        int target = scanner.nextInt();

        // Find the two indices and print them
        int[] result = findTwoSum(nums, target);
        System.out.println(result[0] + " " + result[1]);

        scanner.close();
    }

    // Function to find indices of two numbers that add up to target
    private static int[] findTwoSum(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;

        // Use two-pointer approach to find the indices
        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) return new int[]{left + 1, right + 1}; // Return 1-indexed positions as required
            else if (sum < target) left++; // Move left pointer right to increase sum
            else right--; // Move right pointer left to decrease sum
        }

        // Since the problem guarantees one solution, we should never reach here
        return new int[]{-1, -1};
    }
}

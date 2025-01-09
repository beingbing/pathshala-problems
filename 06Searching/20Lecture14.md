# place the cows
## Problem
A farmer has n stalls and c cows such that c <= n and every cow sits in 1 separate stall. Cows has a tendency to become aggressive on each other if they are too close hence farmer wants to keep minimum distance between adjacent cow stalls as large as possible. Given n, c and location of n stalls as points on x-axis (not necessarily in sorted order), help farmer in finding a solution. There are atleast two cows and two stalls for each test case and if number of cows is more than number of stalls then return 0, as it is an impossible task.

### Solution
#### Key Insights
1. **Sorting the Stall Positions**: We first sort the stall positions. This allows us to think of the stalls as being in a linear order, making it easier to place cows with maximum separation.
2. **Binary Search on the Distance**: Our goal is to maximize the minimum distance between any two cows. Let’s call this minimum distance `d`. We can set up a binary search on `d`, ranging from nearest adjacent stalls to the distance between the farthest stall positions.
3. **Placing Cows with a Given Distance**: For a candidate distance `d`, we try to place cows in the stalls such that the minimum distance between any two cows is at least `d`. By placing the first cow in the first stall, then attempt to place each subsequent cow in a stall that is at least `d` units away from the last placed cow. If we can place all cows with this distance, then `d` is feasible. Otherwise, `d` is too large.
4. **Maximize Distance**: If a candidate distance `d` is feasible, we try a larger `d` (increase the binary search lower bound) to maximize it. If `d` is not feasible, we reduce `d` (decrease the binary search upper bound). The largest feasible `d` found by this search is our answer.
5. **Edge Cases**:
- **More cows than stalls**: If `C > N`, output `0` immediately since it's impossible to place more cows than stalls.
- **Minimum stalls**: With only 2 stalls, the answer is the distance between them.
- **Identical stall positions**: This results in a minimum distance of zero, so ensure the input array has unique or well-spaced values.

#### Code
```java
import java.util.Arrays;
import java.util.Scanner;

public class AggressiveCows {
    // Function to check if a minimum distance `dist` is feasible
    private static boolean canPlaceCows(int[] stalls, int cows, int dist) {
        int count = 1;  // Start by placing the first cow in the first stall
        int lastPos = stalls[0];  // Position of the last placed cow

        // Try to place remaining cows
        for (int i = 1; i < stalls.length; i++) {
            if (stalls[i] - lastPos >= dist) {  // Check if we can place next cow here
                count++;
                lastPos = stalls[i];  // Update last position
                if (count == cows) return true;  // All cows placed successfully
            }
        }
        return false;  // Not enough stalls to place all cows with `dist` spacing
    }

    public static int largestMinimumDistance(int[] stalls, int cows) {
        Arrays.sort(stalls);  // Sort stalls for linear placement

        int n = stalls.length;
        int left = Integer.MAX_VALUE;  // Smallest possible distance
        for (int i = 1; i < n; i++) left = Math.min(left, stalls[i] - stalls[i - 1]);

        int right = stalls[n - 1] - stalls[0];  // Largest possible distance
        int maxDist = 0;

        // Binary search for the maximum feasible minimum distance
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canPlaceCows(stalls, cows, mid)) {
                maxDist = mid;  // Mid is feasible, try for a larger distance
                left = mid + 1;
            } else right = mid - 1;  // Mid is too large, try for a smaller distance
        }
        return maxDist;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input: Number of stalls
        int N = scanner.nextInt();
        int[] stalls = new int[N];
        for (int i = 0; i < N; i++) stalls[i] = scanner.nextInt();

        // Input: Number of test cases
        int T = scanner.nextInt();
        while (T-- > 0) {
            int C = scanner.nextInt();

            // Handle case where cows exceed number of stalls
            if (C > N) System.out.println(0);
            else System.out.println(largestMinimumDistance(stalls, C));
        }
        scanner.close();
    }
}
```

#### Discussion
- **Greedy:** whatever is best possible option for you right now, do it currently, as soon as possible.
- **Greedy Placement of Cows**: By placing each cow in the next available stall that satisfies the minimum distance, we ensure that we're not wasting any stall placements unnecessarily.

#### Complexity Analysis
- **Time Complexity**:
    - Sorting the stalls takes `O(N log N)`.
    - Binary search on the distance has `O(log(maxDistance))` iterations.
    - For each binary search iteration, `canPlaceCows` scans the array in `O(N)`, making the overall time complexity `O(N log N + N log(maxDistance))`.

- **Space Complexity**: The space complexity is `O(1)` additional space, not counting input storage.

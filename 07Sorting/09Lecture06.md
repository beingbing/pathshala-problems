# Dealing with Absolute Values
- Absolute values often represent distances between two numbers.
- The **Manhattan distance** between two points `(x1, y1)` and `(x2, y2)` is defined as:  
```
d = |x2 - x1| + |y2 - y1|
```

## Problem 1: Minimum and Maximum Absolute Differences in an Array
Given an array `a` of size `n`, find:
1. Maximum value of `|a[i] - a[j]|` such that `i != j`.
2. Minimum value of `|a[i] - a[j]|` such that `i != j`.

## Solution

### Finding the Maximum Absolute Difference
The maximum absolute difference between two elements is the difference between the smallest and largest elements in the array.

#### Approach
1. Find the minimum and maximum values in the array.
2. Compute their difference.

#### Complexity
- Time: `O(n)` (single pass to find min and max).
- Space: `O(1)`

### Finding the Minimum Absolute Difference
The minimum absolute difference is the smallest gap between two adjacent elements in a sorted array.

#### Approach
1. Sort the array.
2. Compute differences between consecutive elements and track the smallest difference.

#### Complexity
- Time: `O(n log n)` (due to sorting).
- Space: `O(1)`

### Code
```java
import java.util.Arrays;

public class AbsoluteDifference {
    // Function to find the maximum absolute difference
    public static int maxAbsDifference(int[] arr) {
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for (int num : arr) {
            min = Math.min(min, num);
            max = Math.max(max, num);
        }
        return max - min;
    }

    // Function to find the minimum absolute difference
    public static int minAbsDifference(int[] arr) {
        Arrays.sort(arr);
        int minDiff = Integer.MAX_VALUE;
        for (int i = 1; i < arr.length; i++) {
            minDiff = Math.min(minDiff, arr[i] - arr[i - 1]);
        }
        return minDiff;
    }

    public static void main(String[] args) {
        int[] arr = {3, 8, 15, 1, 5};
        System.out.println("Max Absolute Difference: " + maxAbsDifference(arr));
        System.out.println("Min Absolute Difference: " + minAbsDifference(arr));
    }
}
```

## Problem 2: Manhattan Distance
Given arrays of `x` and `y` coordinates of `n` points, find the sum of Manhattan distances between all pairs of points.

### Solution 1: Brute Force
1. Iterate over all pairs of points and compute the distance for each pair.
2. Sum all the computed distances.

#### Complexity
- Time: `O(n^2)`
- Space: `O(1)`

### Solution 2: Optimized Using Prefix and Suffix Sums
The key insight is that Manhattan distances can be computed efficiently if points are sorted.

#### Key Observations:
1. When points are sorted, `|xi - xj|` can be expressed as: `|xi - xj| = xj - xi (for xj >= xi)`
2. Contributions of a point `xi` are:
   - Positive contributions from all points to its right.
   - Negative contributions from all points to its left.

#### Formula:
For each point `x[i]`:  
```
Contribution = (Suffix Sum of x starting from i + 1) - ( (n - i - 1) * x[i] )
```

#### Optimized Algorithm
1. Sort the `x` and `y` coordinates.
2. Use prefix and suffix sums to compute contributions efficiently.
3. Repeat the process for both `x` and `y` coordinates and sum their results.

#### Complexity
- Time: `O(n log n)`  
- Space: `O(1)`

#### Code
```java
import java.util.Arrays;

public class ManhattanDistance {
    // Calculate the sum of distances for one coordinate array
    public static int distanceSum(int[] arr) {
        Arrays.sort(arr);
        int n = arr.length;
        int totalSum = 0, suffixSum = 0;

        // Compute total sum of elements
        for (int num : arr) suffixSum += num;

        int result = 0;

        // Calculate contributions of each element
        for (int i = 0; i < n; i++) {
            suffixSum -= arr[i];
            result += suffixSum - (n - i - 1) * arr[i];
        }
        return result;
    }

    // Compute total Manhattan distance
    public static int totalDistanceSum(int[] x, int[] y) {
        return distanceSum(x) + distanceSum(y);
    }

    public static void main(String[] args) {
        int[] x = {-1, 1, 3, 2};
        int[] y = {5, 6, 5, 3};
        System.out.println("Total Manhattan Distance: " + totalDistanceSum(x, y));
    }
}
```


Approach 2 -
If all points are sorted in ascending order then |xi - xj| can be treated as (xi - xj) 
One way is -
Example, given 5 points x0, x1, x2, x3 and x4
we have contribution of x0 as: (x1 - x0) + (x2 - x0) + (x3 - x0) + (x4 - x0) = x1 + x2 + x3 + x4 - 4x0 = sufSum[1] - 4x0 = (totalSum - x0) - 4x0
we have contribution of x1 as: (x2 - x1) + (x3 - x1) + (x4 - x1) = x2 + x3 + x4 - 3x1 = sufSum[2] - 3x1 = (totalSum - x0 - x1) - 3x1
we have contribution of x2 as: (x3 - x2) + (x4 - x2) = x3 + x4 - 2x2 = sufSum[3] - 2x2 = (totalSum - x0 - x1 - x2) - 2x2
we have contribution of x3 as: (x4 - x3) = x4 - x3 = sufSum[4] - x3 = (totalSum - x0 - x1 - x2 - x3) - x3
addition of all those 4 equation will give us total manhattan distance for x-axis
similarly, we can do for y-axis

so, to generalize it -
- sorting x coordinates in ascending order (to start with the left-most point on x-axis, so that all mod() of distance opens with a +ve sign)
- sorting y coordinates in ascending order (to start with the bottom-most point on y-axis, so that all mod() of distance opens with a +ve sign)
- ans += XsufArr[i+1] - (n-i-1)*x[i] or ans += (XtotalSum - XpreSum[i]) - (n-i-1) * x[i]
- ans += YsufArr[i+1] - (n-i-1)*y[i] or ans += (YtotalSum - YpreSum[i]) - (n-i-1) * y[i]


other way is -
Example, given 5 points x0, x1, x2, x3 and x4
we have contribution of x4 as: (x4 - x3) + (x4 - x2) + (x4 - x1) + (x4 - x0) = 4 * x4 - (x0 + x1 + x2 + x3)
we have contribution of x3 as: (x3 - x2) + (x3 - x1) + (x3 - x0) = 3 * x3 - (x0 + x1 + x2)
we have contribution of x2 as: (x2 - x1) + (x2 - x0) = 2 * x2 - (x0 + x1)
we have contribution of x1 as: (x1 - x0) = x1 - x0
so, to generalize -
ans += i * xi - prefixSum[i-1];
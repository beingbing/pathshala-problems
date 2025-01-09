#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size()) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int lo = 0;
        int hi = m*n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (matrix[mid/m][mid%m] == target) return true;
            else if (matrix[mid/m][mid%m] < target) lo = mid+1;
            else hi = mid-1;
        }
        return false;
    }
};

```java
public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;

        // Binary search on a virtual 1D representation of the matrix
        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            // Calculate the middle index
            int mid = left + (right - left) / 2;

            // Map the mid index to a row and column in the 2D matrix
            int row = mid / n;
            int col = mid % n;

            // Get the element at the calculated row and column
            int midElement = matrix[row][col];

            if (midElement == target) return true;
            else if (midElement < target) left = mid + 1;
            else right = mid - 1;
        }

        // Target not found
        return false;
    }
}
```
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n-1;
        bool found = false;
        while (i < m and j >= 0) {
            // cout << "i: " << i << endl;
            // cout << "j: " << j << endl;
            if (target < matrix[i][j]) j--;
            else if (target > matrix[i][j]) i++;
            else {
                found = true;
                break;
            }
        }
        return found;
    }
};

int main() {
    vector<vector<int> > matrix = {
                                    {1, 4, 7, 11, 15},
                                    {2, 5, 8, 12, 19},
                                    {3, 6, 9, 16, 22},
                                    {10, 13, 14, 17, 24},
                                    {18, 21, 23, 26, 30}
                                  };
    Solution *obj = new Solution();
    bool ans = obj->searchMatrix(matrix, 5);
    // cout << "ans: " << ans << endl;
    return 0;
}
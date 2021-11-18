/*
    simple statement:
    if at index idx we have an element >= (no of elements to its right + 1(1 for itself))
    then largest of such indexes is our answer
*/
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& a) {
        int n = a.size();
        int low = 0, high = n-1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if(a[mid] >= (n-mid)) high = mid - 1;
            else low = mid + 1;
        }
        return n-low;
    }
};

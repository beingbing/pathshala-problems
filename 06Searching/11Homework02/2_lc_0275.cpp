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

```java
public class Solution {
    public static int hIndex(int[] citations) {
        int n = citations.length;
        int low = 0;
        int high = n - 1;

        // Binary search to find the maximum possible h-index
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int h = n - mid;  // the count of papers from mid to the end of the array

            if (citations[mid] >= h) high = mid - 1; // This mid satisfy a[i] >= n-i, move left to minimize i and for a higher h
            else low = mid + 1; // This mid does not satisfy h-index (a[i] >= n-i), search right
        }

        // After binary search, low points to the first index that satisfies the h-index condition
        return n - low;
    }

    public static void main(String[] args) {
        // Example usage:
        int[] citations = {0, 1, 3, 5, 6};
        System.out.println(hIndex(citations)); // Output: 3
    }
}
```
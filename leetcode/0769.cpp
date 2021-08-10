// max chuncks to make sorted

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int val{INT_MIN}, cnt{0};
        for (int i{0}; i<n; i++) {
            val = max(val, arr[i]);
            if (i == val) cnt++;
        }
        return cnt;
    }
};
// trapping rain water

class Solution {
public:
    int trap(vector<int>& hts) {
        int n = hts.size();
        vector<int> preAr(n), sufAr(n);
        preAr[0] = hts[0];
        for (int i{1}; i<n; i++) preAr[i] = max(preAr[i-1], hts[i]);
        sufAr[n-1] = hts[n-1];
        for (int i{n-2}; i>=0; i--) sufAr[i] = max(sufAr[i+1], hts[i]);
        vector<int> res(n);
        for (int i{0}; i<n; i++) res[i] = min(preAr[i], sufAr[i]);
        int ans{0};
        for (int i{0}; i<n; i++) ans += (res[i] - hts[i]);
        return ans;
    }
};
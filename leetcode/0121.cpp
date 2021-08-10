// Best time to buy and sell stock 1

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> minPre(n), maxSuf(n);
        minPre[0] = prices[0];
        for (int i{1}; i<n; i++) minPre[i] = min(minPre[i-1], prices[i]);
        maxSuf[n-1] = prices[n-1];
        for (int i{n-2}; i>=0; i--) maxSuf[i] = max(maxSuf[i+1], prices[i]);
        int ans{INT_MIN}, temp;
        for (int i{0}; i<n; i++) {
            temp = maxSuf[i] - minPre[i];
            if (ans < temp) ans = temp;
        }
        return ans;
    }
};
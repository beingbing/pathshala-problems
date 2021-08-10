// best time to buy and sell stock 3

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> t1MinBuy(n), t1MaxProfit(n);
        t1MinBuy[0] = prices[0];
        for (int i{1}; i<n; i++) t1MinBuy[i] = min(t1MinBuy[i-1], prices[i]);
        t1MaxProfit[0] = 0;
        for (int i{1}; i<n; i++)
            t1MaxProfit[i] = max(t1MaxProfit[i-1], prices[i]-t1MinBuy[i-1]);
        vector<int> t2MaxFutureSell(n), t2MaxProfit(n);
        t2MaxFutureSell[n-1] = prices[n-1];
        for (int i{n-2}; i>=0; i--) t2MaxFutureSell[i] = max(t2MaxFutureSell[i+1], prices[i]);
        t2MaxProfit[n-1] = 0;
        for (int i{n-2}; i>=0; i--)
            t2MaxProfit[i] = max(t2MaxProfit[i+1], t2MaxFutureSell[i+1] - prices[i]);
        int profit = t2MaxProfit[0];
        for (int i{1}; i<n; i++)
            profit = max(profit, t1MaxProfit[i-1] + t2MaxProfit[i]);
        return profit;
    }
};
// best time to buy and sell stock 3
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // calculate profit made with each new index encountered
        // prefix profit calculation
        vector<int> t1MaxProfit(n);
        int t1MinBuy = prices[0];
        t1MaxProfit[0] = 0;
        for (int i{1}; i<n; i++) {
            t1MinBuy = min(t1MinBuy, prices[i]);
            t1MaxProfit[i] = max(t1MaxProfit[i-1], prices[i]-t1MinBuy);
        }

        // calculate profit made with each new index encountered
        // suffix profit calculation
        vector<int> t2MaxProfit(n);
        int t2MaxFutureSell = prices[n-1];
        t2MaxProfit[n-1] = 0;
        for (int i{n-2}; i>=0; i--) {
            t2MaxFutureSell = max(t2MaxFutureSell, prices[i]);
            t2MaxProfit[i] = max(t2MaxProfit[i+1], t2MaxFutureSell - prices[i]);
        }

        // checking max profit that can be obtained at each index
        // it is same as maximizing the equation
        int profit = t2MaxProfit[0];
        for (int i{1}; i<n; i++)
            profit = max(profit, t1MaxProfit[i-1] + t2MaxProfit[i]);
        return profit;
    }
};

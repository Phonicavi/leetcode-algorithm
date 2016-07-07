class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (!len) return 0;
        int *dp = new int[len];
        dp[len-1] = prices[len-1];
        for (int j = len-1; j > 0; --j) {
            dp[j-1] = (prices[j-1]>prices[j])?max(prices[j-1], dp[j]):dp[j];
        }
        int max_profit = 0;
        for (int j = 0; j < len; ++j) {
            max_profit = max(max_profit, dp[j]-prices[j]);
        }
        return max_profit;
    }
};
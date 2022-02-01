class Solution {
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0; 
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                max_profit = max(max_profit, prices[j] - prices[i]);
            }
        }      
        return max_profit;
    }
};
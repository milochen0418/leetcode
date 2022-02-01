class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0; 
        int min_price = prices[0];
        for(int j=1;j<n;j++) { 
            min_price = min(min_price, prices[j]);
            max_profit = max( max_profit, prices[j] - min_price);            
        }        
        return max_profit;
    }
};
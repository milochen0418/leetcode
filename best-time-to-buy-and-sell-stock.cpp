class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0; 
        for(int j=1;j<n;j++) { 
            int min_price = INT_MAX;
            for(int i=0;i<j;i++) {
                min_price = min(min_price, prices[i]);
            }
            max_profit = max( max_profit, prices[j] - min_price);            
        }        
        return max_profit;
    }
};
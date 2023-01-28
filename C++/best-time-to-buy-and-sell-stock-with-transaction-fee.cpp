class Solution {
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> dp = vector<int>(prices.size(),-1); 
        vector<int> minp = vector<int>(prices.size(),-1); 
        //Idea, is possible to make minp quickly?. is it helpful?
        /*
        int minv = prices[i];
        for(int j = 0;j<n;j++) {
            minv = min(minv, prices[j]);
            minp[i] = minv;
        }
        */
        
        function<int(int)> sol = [&prices, &sol, &dp, &fee](int i) {
            int ans=0, cost = 0, n=prices.size();
            if(i>=n) return 0;
            if(dp[i]!=-1) return dp[i];
            
            int minv = prices[i] ;
            for(int j = i;j<n;j++) {
                cost = max(cost, prices[j]-minv);
                minv = min(minv, prices[j]);
                //ans = max(ans, cost-feesol(j+2));
                if(cost>fee)
                ans = max(ans, cost-fee+sol(j+1));
            }
            return dp[i]=ans;
        };
        int bestearn = sol(0);
        return bestearn;
    }
        
    
};
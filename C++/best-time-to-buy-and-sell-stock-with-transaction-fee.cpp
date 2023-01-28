class Solution {
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
public:
    
    //Pay fee first when edge start. total sum>0 and add it. 
        //Idea, just sell it in every rise edge
    int maxProfit(vector<int>& prices, int fee) {
    /*      
                +1
          a     /
          +    /
          /\  /
         /  \/
        /    + b
       /
     +0 
        The hard prolem to decide cut of or not?
        if(fee < |v[a]-v[b] |) { 
            set cut_early = true; 
        }
        
        if( cut_early) {
            ans +=(|v[a]-v[0]| - fee) only do it if ans can get increasing 
        } else (!early cut) {
            figure out |v[1]-v[0]| = |v[a..0]| - |v[a..b]| + |v[b..1]| 
            //Thus, v just keep increasing in this case
        }          
    */  
        //The following code of best-time-to-buy-and-sell-stock-ii
        //We will use above anlysis result to adjust it into our solution.
        int n = prices.size();
        int v = 0, ans = 0;
        for(int i =1;i<n;i++) {
            if(prices[i] - prices[i-1] >0) {
                v+=prices[i] - prices[i-1];
            } else {
                if(i+1<n && prices[i+1] - prices[i] > 0) {
                    //The point in the valley 
                    ans+=v;
                    v = 0;                    
                } else {
                    //case of keeping in the falling edge
                }
            }
        }
        return ans;
    }
    
    int maxProfit_v01(vector<int>& prices, int fee) {//TLE
        vector<int> dp = vector<int>(prices.size(),-1); 
        vector<int> minp = vector<int>(prices.size(),-1);         
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
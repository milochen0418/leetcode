class Solution {
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
    //article https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/3109092/C%2B%2B-Use-similar-DP-of-House-Robber-to-solve
public:
    
    #define printf(...) empty_printf(__VA_ARGS__)
    #define empty_printf(...)    
    #define print_container(name) printf("%s = ",#name);for(auto &i:name)printf("%d,",i);printf("\n");
    int maxProfit(vector<int>& prices) {
        print_container(prices);
        //Use a little bit idea of  Robber House to think about this idea
        /*
         0 1 2 3 4 
        [1,2,3,0,2]
        cost(i=0) + sol(i+2=2) <-- no way. because buy first and then sell
        .So the first sell must happen in cost(i=1)
        
        cost(i=1) + sol(i+2=3)
        cost(i=2) + sol(i+2=4)
        */
        
        /*[2,1,2,3,0,2]
        cost(i=1) + sol(i+2=3)
        if(we buy for A[0], that's the worst decision)
        cost(i=2) + sol(i+2=4)
        cost(i=3) + sol(i+2=5)
        
        sol(i+2=5) also mean sell (i=3) before. so that why we have sol(i+2=5)
        So sol(0) is mean we sell in cost(-1)=0. And start to find optimize value for sol(0)
        */
        
        vector<int> dp = vector<int>(prices.size(),-1); 
        function<int(int)> sol = [&prices, &sol, &dp](int i) {
            printf("sol(i=%d)\n",i);
            int ans=0, cost = 0, n=prices.size();
            if(i>=n) {
                printf("i>=n, return 0 early\n");
                return 0;
            }
            if(dp[i]!=-1) return dp[i];
            
            int minv = prices[i] ;
            printf("sol(i=%d), n=%d\n",i,n);
            for(int j = i;j<n;j++) {
                cost = max(cost, prices[j]-minv);
                minv = min(minv, prices[j]);
                int sol_j_2 = sol(j+2);
                
                ans = max(ans, cost+sol_j_2);
                printf("j=%d: cost+sol(j+2=%d) = %d + %d => new ans=%d\n",j,j+2, cost, sol_j_2, ans );
            }
            return dp[i]=ans;
            //return ans;
        };
        int bestearn = sol(0);
        return bestearn;
    }
};
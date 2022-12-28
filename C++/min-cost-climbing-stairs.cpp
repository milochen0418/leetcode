class Solution {
    //https://leetcode.com/problems/min-cost-climbing-stairs
    //article https://leetcode.com/problems/min-cost-climbing-stairs/discuss/2197248/C%2B%2B-or-top-down-dynamic-programming-or-explanation
public:
    vector<int>* pCost;
    vector<int> dp;
    int minCostClimbingStairs(vector<int>& cost) {
        pCost = &cost;
        int n = cost.size();
        dp = vector<int>(n+1, -1);
        dp[0] = dp[1] = 0;
        return sol(n);    
    }
    int sol(int i) {
        if(dp[i]!=-1)return dp[i];
        vector<int>& cost=*pCost;
        if(i<=1) 
            dp[i]=0;
        else 
            dp[i] = min(cost[i-2]+sol(i-2), cost[i-1]+sol(i-1));
        return dp[i];
    }
    /*
    int minCostClimbingStairs(vector<int>& cost) {
        pCost = &cost;
        int n = cost.size();
        dp = vector<int>(n+1, -1);
        return sol(n); 
        
    }
    int sol(int i) {
        if(dp[i]!=-1)return dp[i];
        vector<int>& cost=*pCost;        
        return dp[i]=i>1?min(cost[i-2]+sol(i-2), cost[i-1]+sol(i-1)):0;
    }

    */
};
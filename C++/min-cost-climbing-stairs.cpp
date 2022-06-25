class Solution {
    //https://leetcode.com/problems/min-cost-climbing-stairs
public:
    vector<int> dp;
    vector<int> cost; 
    int minCostClimbingStairs(vector<int>& a) {
        cost = a;
        int n = cost.size();
        dp = vector<int>(n+2,INT_MAX);
        dp[n] = 0;
        dp[n+1] = 0;
        return min(sol(0), sol(1));
    }
    int sol(int n) {
        if(dp[n] != INT_MAX) return dp[n];
        dp[n] = min(dp[n], cost[n] + sol(n+1));
        dp[n] = min(dp[n], cost[n] + sol(n+2));
        return dp[n];
    }
};
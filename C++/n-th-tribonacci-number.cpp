class Solution {
    //https://leetcode.com/problems/n-th-tribonacci-number
public:
    vector<int> dp;
    int tribonacci(int n) {
        dp = vector<int>(n+3,-1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        return sol(n);
    }
    int sol(int n) {
        if(dp[n]!=-1) return dp[n];
        dp[n] = sol(n-1) + sol(n-2) + sol(n-3);
        return dp[n];
    }  
};
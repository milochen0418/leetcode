class Solution {
    //https://leetcode.com/problems/climbing-stairs
public:
    vector<int> dp;
    int climbStairs(int n) {
        //return sol_backtrace(0,n);
        dp = vector<int>(n+1,0);
        dp[0]=1;
        return sol_dp(0,n);
    }
    int sol_dp(int start, int end) {
        if(end-start<0) return 0;
        if(dp[end-start] != 0) return dp[end-start];
        dp[end-start] = sol_dp(start+2,end) + sol_dp(start+1,end);
        return dp[end-start];
    }
    int sol_backtrace(int start, int end) {        
        if(end-start==0) return 1;
        if(end-start<0) return 0;
        return sol_backtrace(start+2,end) + sol_backtrace(start+1,end);
    }
};
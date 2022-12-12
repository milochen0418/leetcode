class Solution {
    //https://leetcode.com/problems/climbing-stairs
    //article https://leetcode.com/problems/climbing-stairs/discuss/2175372/C%2B%2B-or-easy-understand-to-do-from-backtrace-to-top-down-DP
    //refer Detailed Explanation of DP https://leetcode.com/explore/featured/card/dynamic-programming/631/strategy-for-solving-dp-problems/4096/
public:

    vector<int> dp;
    int climbStairs(int n) {
        dp = vector<int>(n+1,0);
        return sol(n);
    }
    int sol(int n) {
        if(dp[n] > 0) return dp[n];
        if(n<=2) {
            dp[n] = n; 
        } else {
            dp[n] = sol(n-1) + sol(n-2);     
        }
        return dp[n];
    }

    int climbStairs_v01(int n) {
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
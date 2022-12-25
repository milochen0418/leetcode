class Solution {
    //https://leetcode.com/problems/fibonacci-number
public:
    vector<int> dp;
    int fib(int n) {
        dp = vector<int>(n+1,-1);
        return sol(n);
    }
    int sol(int n) {
        if(dp[n] != -1) return dp[n];
        if(n<=1)
            dp[n]=n;
        else
            dp[n] = sol(n-1) + sol(n-2);
        return dp[n];
    }
};
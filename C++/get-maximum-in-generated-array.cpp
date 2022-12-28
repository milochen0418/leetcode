class Solution {
    //https://leetcode.com/problems/get-maximum-in-generated-array 
    //article https://leetcode.com/problems/get-maximum-in-generated-array/discuss/2962836/C%2B%2B-or-DP-or-TC%3AO(N)-SC%3AO(N)
public:
    vector<int> dp;
    int getMaximumGenerated(int n) {
        dp = vector<int>(n+1+1,-1);
        int ans=-1;
        for(int i = 0;i<n+1;i++) ans=max(ans, sol(i));
        return ans;
    }
    int sol(int n) {
        if(dp[n]!=-1) return dp[n];
        if(n<=1) 
            dp[n] = n;
        else if(n%2==0) 
            dp[n] = sol(n/2);
        else
            dp[n] = sol((n-1)/2) + sol(1+ (n-1)/2);
        return dp[n];
    }
};
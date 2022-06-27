class Solution {
    //https://leetcode.com/problems/jump-game-ii/
public:
    vector<int> a;
    vector<int> dp;
    int jump(vector<int>& nums) {
        a = nums;
        int n = a.size();
        dp = vector<int>(n,-1);
        dp[n-1] = 0;
        return sol_dp(0);
        //return sol_bt(0);
    }
    int sol_dp(int i) {//dp: dynamic programming
        int n = a.size();
        if(i>=n) return INT_MAX;
        if(dp[i]!=-1) return dp[i];
        int m = INT_MAX;
        for(int j = 1; j<=a[i]; j++) {
            if( (i+j)>(n-1) ) break;
            m = min(m, sol_dp(i+j)); 
        }
        dp[i] = m<INT_MAX?1+m:m; 
        return dp[i];
    }
    int sol_bt(int i) { //bt: backtrace
        int n = a.size();
        if(i>=n) return INT_MAX;
        if(i==n-1) return 0;
        int m = INT_MAX;
        for(int j = 1; j<=a[i]; j++) {
            if( (i+j)>(n-1) ) break;
            m = min(m, sol_bt(i+j)); 
        }
        return m<INT_MAX?1+m:m;
    }    
};
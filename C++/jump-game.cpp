class Solution {
    //https://leetcode.com/problems/jump-game
public:
    vector<int> a;
    vector<int> dp;
    bool canJump(vector<int>& nums) {
        a = nums;
        int n = a.size();
        dp = vector<int>(n,-1);
        dp[n-1] = 1;
        return sol(0);
        
    }
    bool sol(int i) {
        int n = a.size();
        if(i>=n) return false;
        if(dp[i] != -1) return dp[i];
        dp[i] = 0;
        for(int j = 1;j<=a[i];j++) if(sol(i+j)) return dp[i] = 1;
        return dp[i];
    }
};
class Solution {
    //https://leetcode.com/problems/jump-game
public:
    vector<int> a;
    vector<int> dp;
    bool canJump(vector<int>& nums) {
        a = nums;
        dp = vector<int>(a.size(),-1);
        return sol(0);
        
    }
    bool sol(int i) {
        int n = a.size();
        if(i>=n) return false;
        if(dp[i] != -1) return dp[i]==1;
        
        if(i==n-1) {
            dp[i] = 1;
        } else {
            bool ans = false;
            for(int j = 1;ans == false &&  j<=a[i];j++) ans |= sol(i+j);
            dp[i] = ans?1:0;
        }
        return dp[i] == 1;
    }
};
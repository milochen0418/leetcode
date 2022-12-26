class Solution {
    //https://leetcode.com/problems/jump-game
public:
    vector<int> dp;
    bool canJump(vector<int>& nums) {
        //return sol_backtracking(0, nums);
        dp = vector<int>(nums.size(), -1);
        return sol_dp(0,nums);
    }
    int sol_dp(int j, vector<int>& A) {
        if(dp[j]!=-1) return dp[j];
        if(j==A.size()-1) {
            dp[j] = 1;
        } else {
            dp[j] = 0;
            for(int i = j+1;i<A.size() && i<=j+A[j];i++) {
                if(sol_dp(i,A)) {                
                    dp[j]=1;
                    break;
                }
            }
        }
        return dp[j];
    }
    
    int sol_backtracking(int j, vector<int>& A) {
        int ret;
        if(j==A.size()-1) {
            ret = 1;
        } else {
            ret = 0;
            for(int i = j+1;i<A.size() && i<=j+A[j];i++) {
                if(sol_backtracking(i,A)) {
                    ret = 1;
                    break;
                }
            }
        }
        return ret;
    }
};
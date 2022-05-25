class Solution {
    //https://leetcode.com/problems/longest-increasing-subsequence
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = vector<int>(n, 0);
        dp[n-1]=1;
        int ans = 0;
        for(int i = 0; i<nums.size();i++) {
            ans = max(ans, sol(i, nums,dp));
        }
        return ans;
    }

    //sol return the maximum longest increasing subsequence containing nums[first_idx]
    int sol(int first_idx, vector<int>& nums, vector<int>&dp) {
        
        if(dp[first_idx]>=1) return dp[first_idx];
        int e = nums[first_idx];
        int max_val = 0;
        for(int i = first_idx+1; i<nums.size();i++) {
            if(e<nums[i]) max_val = max(max_val, 1+sol(i,nums,dp));
        }
        dp[first_idx] = max_val==0?1:max_val;
        return dp[first_idx];
    }
};
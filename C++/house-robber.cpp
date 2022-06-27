class Solution {
    //https://leetcode.com/problems/house-robber
public:
    vector<int> a;
    vector<int> dp;
    int rob(vector<int>& nums) {
        a = nums;
        int n = a.size();
        dp = vector<int>(n+1,-1);
        return sol(0);
    }
    int sol(int i) {
        int n = a.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        dp[i] = max(a[i] + sol(i+2), sol(i+1)); 
        //ans of the case that include a[i] is a[i] + sol(i+2)
        //ans of the case that not include a[i]  is sol(i+1)
        return dp[i];
    }
};
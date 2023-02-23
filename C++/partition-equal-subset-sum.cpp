class Solution {
    //https://leetcode.com/problems/partition-equal-subset-sum
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto &i:nums) sum+=i;
        if(sum%2!=0) return false;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int M = 200*100+1;
        vector<vector<int>> dp = vector<vector<int>>(200+1, vector<int>(2*(M), -1));

        function<int(int,int)> sol = [&](int i, int diff) {
            if(dp[i][diff+M] != -1) return dp[i][diff+M];
            if(i == n) return (int)(diff==0);
            if( sol(i+1, diff+nums[i]) )
                return dp[i][diff+M] = 1;
            if( sol(i+1, diff-nums[i]) )
                return dp[i][diff+M] = 1;
            return dp[i][diff+M] = 0;
        };
        return sol(0,0);
    }

    bool canPartition_backtracking(vector<int>& nums) {
        int sum = 0;
        for(auto &i:nums) sum+=i;
        if(sum%2!=0) return false;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        function<int(int,int)> sol = [&](int i, int diff) {
            //diff = selection - no-selection
            // You want to find diff s.t. 
            if(i == n) {
                return (int)(diff==0);
            } else {
                if( sol(i+1, diff+nums[i]) ) return 1;
                if( sol(i+1, diff-nums[i]) ) return 1;
                return 0;                
            }
        };
        return sol(0,0);
        
    }
};
class Solution {
    //https://leetcode.com/problems/jump-game
    //article https://leetcode.com/problems/jump-game/discuss/2951627/C%2B%2B-or-from-backtracking-(TLE)-to-DP
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp = vector<int> (nums.size(),-1);
        function<int(int)> sol = [&](int i){
            int n = nums.size();
            if(dp[i] != -1) return dp[i];
            if(i==n-1) return dp[i]=1;
            int limit = min(n-1,i+nums[i]);
            for(int j =i+1;j<=limit;j++) 
                if(sol(j)) return dp[i]=1;
            return dp[i]=0;
        };
        return sol(0);
    }


    vector<int> dp;
    bool canJump_v01(vector<int>& nums) {
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
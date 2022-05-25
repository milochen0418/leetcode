class Solution {
    //https://leetcode.com/problems/russian-doll-envelopes
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<int> dp = vector<int>(n, 0);
        dp[n-1]=1;
        int ans = 0;
        sort(envelopes.begin(), envelopes.end(), [](auto& lhs, auto& rhs){
           return lhs[0]<rhs[0]; 
        });
        for(int i = 0; i<envelopes.size();i++) {
            int can_sol = sol(i, envelopes,dp);
            //printf("[%d]->%d\n", i,can_sol);
            ans = max(ans, can_sol);
        }
        return ans;
    }
    int sol(int first_idx, vector<vector<int>>& envs, vector<int>&dp) {
        if(dp[first_idx]>=1) return dp[first_idx];
        vector<int>& e = envs[first_idx];
        int max_val = 0;
        for(int i = first_idx+1; i<envs.size();i++) {
            if(e[0]<envs[i][0] && e[1]<envs[i][1])
                max_val = max(max_val, 1+sol(i,envs,dp));
        }
        dp[first_idx] = max_val==0?1:max_val;
        return dp[first_idx];
    }    
};
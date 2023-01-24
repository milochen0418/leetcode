class Solution {
    //https://leetcode.com/problems/longest-increasing-subsequence
    //https://leetcode.com/problems/longest-increasing-subsequence/discuss/2072683/C%2B%2B-or-Dynamic-Programming-(Top-Down)
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


    

    int lengthOfLIS_TLE(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> allpath;
        vector<int> stk;
        function<void(int)> dfs = [&](int i){
            stk.push_back(nums[i]);
            int is_no_leaf = 1;
            for(int j = i+1;j<n;j++) {
                if(nums[j]>stk.back()) {
                    dfs(j);   
                    is_no_leaf = 0;
                }
            }
            if(is_no_leaf) {
                allpath.push_back(stk);
            }
            stk.pop_back();
        };
        for(int i = 0;i<nums.size();i++) dfs(i);
        /*
        for(auto &path:allpath) {
            for(auto &i:path) printf("%d,", i);
            printf("\n");
        }*/
        int ans = 0;
        int maxlen = 0;
        for(auto &path:allpath) maxlen = max(maxlen, (int)path.size());
        return maxlen;
        //for(auto &path:allpath) if(maxlen == (int)path.size())ans++;
        //return ans;

    }




};
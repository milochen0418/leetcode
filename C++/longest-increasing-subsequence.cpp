class Solution {
    //https://leetcode.com/problems/longest-increasing-subsequence
    //https://leetcode.com/problems/longest-increasing-subsequence/discuss/2072683/C%2B%2B-or-Dynamic-Programming-(Top-Down)
public:
    int lengthOfLIS(vector<int>& nums) {
        //DP solution O(N^2)
        int n = nums.size();
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n,-1));
        function<int(int,int)> sol = [&](int L,int R){
            if(R>=n) return 0;
            int& dpv = dp[L+1][R];
            if(dpv != -1) return dpv;
            if(nums[R] <= (L<0?INT_MIN:nums[L]))
                return dpv = sol(L,R+1);
            else
                return dpv = max(1+sol(R,R+1), sol(L,R+1));
        };
        return sol(-1,0);
    }

    int lengthOfLIS_observation(vector<int>& nums) {
        //Do some observation 
        /*
        Input: [10,9,2,5,3,7,101,18]
        stdout:
        L\R	R=0	R=1	R=2	R=3	R=4	R=5	R=6	R=7	
        L=0	4	4	4	3	3	2	1	1	
        L=1	1	1	1	1	1	1	1	1	
        L=2	2	1	1	1	1	1	1	1	
        L=3	3	3	3	3	3	2	1	1	
        L=4	2	2	2	2	2	2	1	1	
        L=5	3	3	3	3	2	2	1	1	
        L=6	2	2	1	1	1	1	1	1	
        L=7	0	0	0	0	0	0	0	0	
        */
        int n = nums.size();
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n,-1));
        function<int(int,int)> sol = [&](int L,int R){
            if(R>=n) return 0;
            int& dpv = dp[L+1][R];
            if(dpv != -1) return dpv;
            if(nums[R] <= (L<0?INT_MIN:nums[L]))
                return dpv = sol(L,R+1);
            else
                return dpv = max(1+sol(R,R+1), sol(L,R+1));
        };
        for(int L = 0; L<n;L++) {
            if(L==0) {
                printf("L\\R\t");
                for(int R=0;R<n;R++) printf("R=%d\t",R);
                printf("\n");
            }
            
            printf("L=%d\t",L);
            for(int R=0;R<n;R++) {
                printf("%d\t", sol(L-1,R));
            }
            printf("\n");
        }
        return sol(-1,0);
    }    


    int lengthOfLIS_v03(vector<int>& nums) {
        //backtracking TLE v01, change two parameter as index of array
        int n = nums.size();
        function<int(int,int)> sol = [&](int L,int R){
            if(R>=n) return 0;
            if(nums[R] <= (L<0?INT_MIN:nums[L]))
                return sol(L,R+1);
            else
                return max(1+sol(R,R+1), sol(L,R+1));
        };
        return sol(-1,0);
    }
    int lengthOfLIS_v02(vector<int>& nums) {
        //backtracking TLE v01 
        int n = nums.size();
        function<int(int,int)> sol = [&](int v,int i){
            if(i>=n) return 0;
            if(nums[i]<=v)
                return sol(v, i+1);
            else 
                return max(1+sol(nums[i],i+1), sol(v, i+1));
        };
        return sol(INT_MIN,0);
    }


    int lengthOfLIS_v01(vector<int>& nums) {
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
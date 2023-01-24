class Solution {
    //https://leetcode.com/problems/jump-game-ii/
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = vector<int>(n,-1);
        function<int(int)> sol = [&](int i){
            if(i>=n) return 0;
            if(dp[i]!=-1) return dp[i];
            if(i==n-1) return dp[i] = 0;
            int limit = min(n-1, i+nums[i]);
            int minv = INT_MAX/2;
            for(int j = i+1;j<=limit;j++) {
                minv = min(minv, sol(j));
            }
            return dp[i]=minv+1;
        };
        return sol(0);
    }

    vector<int> a;
    vector<int> dp;
    int jump_v01(vector<int>& nums) {
        a = nums;
        int n = a.size();
        dp = vector<int>(n,-1);
        dp[n-1] = 0;
        return sol_dp(0);
        //return sol_bt(0);
    }
    int sol_dp(int i) {//dp: dynamic programming
        int n = a.size();
        if(i>=n) return INT_MAX;
        if(dp[i]!=-1) return dp[i];
        int m = INT_MAX;
        for(int j = 1; j<=a[i]; j++) {
            if( (i+j)>(n-1) ) break;
            m = min(m, sol_dp(i+j)); 
        }
        dp[i] = m<INT_MAX?1+m:m; 
        return dp[i];
    }
    int sol_bt(int i) { //bt: backtrace
        int n = a.size();
        if(i>=n) return INT_MAX;
        if(i==n-1) return 0;
        int m = INT_MAX;
        for(int j = 1; j<=a[i]; j++) {
            if( (i+j)>(n-1) ) break;
            m = min(m, sol_bt(i+j)); 
        }
        return m<INT_MAX?1+m:m;
    }    
};
class Solution {
    //https://leetcode.com/problems/house-robber
    //article https://leetcode.com/problems/house-robber/discuss/2204532/C%2B%2B-or-2-kind-of-view-to-make-Top-Down-DP
public:

    //by the code of rob_v02, you can write done DP code with space O(1)
    int rob(vector<int>& nums) {
        vector<int>& A = nums;
        int n = nums.size();
        int next_next = 0;
        int next = A[n-1];
        n = n-2;
        int cur=next;
        while(n>=0) {
            cur = max(A[n] + next_next, next);
            next_next = next;
            next = cur;
            n=n-1;
        }
        return cur;
    }
    

    vector<int> dp;
    int rob_v02(vector<int>& nums) {
        int n = nums.size();
        dp = vector<int>(n+1,-1);
        return sol_v02(0, nums);
    }
    int sol_v02(int i, vector<int>& A) {
        if(dp[i] >=0) return dp[i];
        int n = A.size();
        if(i>=n) 
            dp[i] = 0;
        else if(i==n-1) 
            dp[i] = A[n-1];
        else 
            dp[i] = max(A[i] + sol_v02(i+2,A),  sol_v02(i+1,A));
        return dp[i];
    }


    vector<int> a;
    
    int rob_v01(vector<int>& nums) {
        a = nums;
        int n = a.size();
        dp = vector<int>(n+1,-1);
        //return sol(0); //dp from head
        return sol2(n-1); //dp from tail
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
    int sol2(int i) {
        if(i<0) return 0;
        if(dp[i] != -1) return dp[i];
        dp[i] = max(a[i] + sol2(i-2), sol2(i-1));
        return dp[i];
    }

};
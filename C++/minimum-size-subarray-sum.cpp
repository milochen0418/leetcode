class Solution {
    //https://leetcode.com/problems/minimum-size-subarray-sum
public:
    vector<int> dp;
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> &a = nums;
        int n = a.size();
        dp = vector<int>(n+1,0);
        for(int i = 0; i<n;i++) {
            int ai_1 = i==0?0:a[i-1];
            a[i] += ai_1;
            //a[i] = i==0?a[i]:a[i-1]+a[i];
        }
        //if M=3; 
        //a[2]-0, a[3]-a[0], a[4]-a[1], a[5]-a[2]
        
        
        int L = 1, R = n;
        while(L<=R) {
            int M = L + (R-L)/2;
            if(isValid(a,M,target) && ((M-1<1) || !isValid(a,M-1,target)) ) return M;
            if(isValid(a,M,target)) R=M-1; else L=M+1;
        }
        //return -1;
        return 0;
    }
    bool isValid(vector<int> &a, int M, int t) {
        if(dp[M]!=0) return dp[M]==1;
        
        int n = a.size();
        for(int i = M-1;i<n;i++) {
            int j = i-M;
            int a_j = j<0?0:a[j];
            int sum = a[i]-a_j;
            if(sum>=t) {
                dp[M]=1;
                return true;
            }
        }
        dp[M]=-1;
        return false;
    }
};
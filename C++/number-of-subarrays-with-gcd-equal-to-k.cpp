class Solution {
    //https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/
public:
    int subarrayGCD(vector<int>& nums, int kk) {
        int ans = 0;
        int n = nums.size();        
        int L=0,R=0;
        int figure_gcd = 0;
        while(L<n && R<n) {
            if(figure_gcd == 0) {
                figure_gcd = nums[L];
                for(int k = L;k<=R;k++) {
                    figure_gcd = gcd(nums[k], figure_gcd);
                }
            } else {
                figure_gcd = gcd(figure_gcd, nums[R]);
            }
            
            if(figure_gcd == kk) {
                ans++;
                R++;
            } else if(figure_gcd > kk){
                R++;
            } 
            
            if(figure_gcd < kk || R>=n) {
                L=L+1;
                R = L;
                figure_gcd = 0;
            } 
        }
        return ans;
    }
    
};
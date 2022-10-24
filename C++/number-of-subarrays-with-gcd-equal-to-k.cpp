class Solution {
    //https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0, L=0,R=0, cur_gcd = 0, n = nums.size();
        while(L<n && R<n) {
            cur_gcd = gcd(cur_gcd, nums[R]);
            if(cur_gcd == k) ans++;
            if(cur_gcd >= k) R++;
            if(cur_gcd < k || R>=n) {
                L = L+1;
                R = L;
                cur_gcd = 0;
            } 
        }
        return ans;
    }    
};
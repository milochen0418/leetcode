class Solution {
    //https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans  = 0,n = nums.size();
        for(int i = 0; i<n; i++) {
            int d = i, kk=0;
            while(d>0) {
                kk+=d%2;
                d=d/2;
            }
            if(kk==k) ans+=nums[i];
        }
        return ans;
    }
};
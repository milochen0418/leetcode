class Solution {
    //https://leetcode.com/problems/maximum-ascending-subarray-sum
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0, maxv=0, prev_i=INT_MAX;
        for(auto &i:nums) {
            maxv = i>prev_i?maxv+i:i;            
            ans = max(maxv,ans);
            prev_i = i;
        }
        return ans;
    }
};
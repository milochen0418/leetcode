class Solution {
    //https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxv = 0, ans = 0;
        for(auto &v:nums) maxv = max(maxv, v);
        for(int i = 0; i<k;i++)  ans+=maxv++;
        return ans;      
    }
};
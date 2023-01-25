class Solution {
    //https://leetcode.com/problems/largest-number-at-least-twice-of-others
public:
    int dominantIndex(vector<int>& nums) {
        int maxv = 0;
        for(auto &i:nums) maxv=max(maxv,i);
        for(auto &i:nums) if(i*2>maxv && maxv>i) return -1;
        for(int i = 0;i<nums.size();i++) if(maxv==nums[i])return i;
        return -1;
    }
};
class Solution {
    //https://leetcode.com/problems/check-if-array-is-good
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto &i:nums) 
            if(i<1||i>=n||++mp[i]>=2+(i==n-1)) return false;
        return true;
    }
};
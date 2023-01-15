class Solution {
    //https://leetcode.com/problems/n-repeated-element-in-size-2n-array
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &i:nums) 
            if(++mp[i]>=nums.size()/2) 
                return i;
        return -1;        
    }
};
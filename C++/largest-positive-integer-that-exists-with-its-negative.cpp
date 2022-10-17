class Solution {
    //https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &i:nums) {
            mp[i]+=1;
        }
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        for(auto &i:nums) {
            if(mp[-1*i]>=1) return i;
        }
        
        return -1;
        
    }
};
class Solution {
    //https://leetcode.com/problems/sort-array-by-increasing-frequency
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> mp = vector<int>(201,0);
        for(auto &i:nums) mp[i+100]++;
        sort(nums.begin(), nums.end(), [&](auto &lhs, auto &rhs){
            if(mp[lhs+100] == mp[rhs+100]) 
                return lhs>rhs;
            else 
                return mp[lhs+100] < mp[rhs+100];     
        });
        return nums;
    }
};
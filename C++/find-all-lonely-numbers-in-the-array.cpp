class Solution {
    //https://leetcode.com/problems/find-all-lonely-numbers-in-the-array
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto &i: nums) mp[i]++;
        for(auto &x:nums) if(mp[x]==1 && mp[x-1]==0 && mp[x+1]==0) ans.push_back(x);
        return ans;
    }
};
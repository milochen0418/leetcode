class Solution {
    //https://leetcode.com/problems/set-mismatch
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &i:nums) mp[i]++;
        int n = nums.size(), duplicate=0, missing=0;
        for(int i = 1;i<=n;i++) {
            if(mp[i]==0) missing=i;
            if(mp[i]==2) duplicate=i;
        }
        return {duplicate, missing};
    }
};
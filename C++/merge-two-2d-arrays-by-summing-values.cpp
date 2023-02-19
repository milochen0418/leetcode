class Solution {
    //https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int> mp;
        for(auto &v: nums1) mp[v[0]]+=v[1];
        for(auto &v: nums2) mp[v[0]]+=v[1];
        vector<vector<int>> ans;
        for(auto &[key,val]: mp) {
            ans.push_back({key,val});
        }
        sort(ans.begin(), ans.end(), [](auto &lhs, auto &rhs){
            return lhs<rhs;
        });
        return ans;
        
        
    }
};
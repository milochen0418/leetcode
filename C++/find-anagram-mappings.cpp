class Solution {
    //https://leetcode.com/problems/find-anagram-mappings
public:
    vector<int>& anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int> mp;
        for(int j = 0; j<n;j++) mp[nums2[j]] = j;
        for(auto &i:nums1) i=mp[i];
        return nums1;
    }
};
class Solution {
    //https://leetcode.com/problems/find-common-elements-between-two-arrays
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), ans1=0,ans2=0;
        vector<int> mp1=vector<int>(101,0), mp2=vector<int>(101,0);
        for(auto &i:nums1) mp1[i]++;
        for(auto &i:nums2) mp2[i]++;
        for(auto &i:nums1) ans1+=(mp2[i]>0);
        for(auto &i:nums2) ans2+=(mp1[i]>0);
        return {ans1, ans2};
    }
};
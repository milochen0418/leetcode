class Solution {
    //https://leetcode.com/problems/minimum-common-value
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for(auto &i:nums2) s.insert(i);
        sort(nums1.begin(), nums1.end());
        for(auto &i: nums1)
            if(s.find(i) != s.end()) 
                return i;
        return -1;
    }
};
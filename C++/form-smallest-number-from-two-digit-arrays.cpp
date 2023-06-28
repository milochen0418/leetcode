class Solution {
    //https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        unordered_set<int> s1;
        for(auto &i:nums1) s1.insert(i);
        for(auto &i:nums2) if(s1.find(i) != s1.end()) return i;
        
        if(nums1[0]<nums2[0])
            return nums1[0]*10 + nums2[0];
        else 
            return nums2[0]*10 + nums1[0];
    }
};
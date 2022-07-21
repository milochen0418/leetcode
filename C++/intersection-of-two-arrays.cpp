class Solution {
    //https://leetcode.com/problems/intersection-of-two-arrays
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> s1;
        unordered_set<int> s2;
        for(auto& i:nums1) s1.insert(i);
        for(auto& i:nums2) if(s1.find(i) != s1.end()) s2.insert(i);
        for(auto &i:s2) ans.push_back(i);
        return ans;
    }
};
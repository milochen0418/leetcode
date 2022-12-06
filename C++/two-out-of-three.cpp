class Solution {
    //https://leetcode.com/problems/two-out-of-three
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> total,s1,s2,s3;
        vector<vector<int>> numss = {nums1, nums2, nums3};
        vector<unordered_set<int>> sets = vector<unordered_set<int>>(3);
        for(int i = 0; i<3;i++) {
            for(auto &val:numss[i]) {
                total.insert(val);
                sets[i].insert(val);
            }
        }
        vector<int> ans;
        for(auto &val:total) {
            int q = 0;
            for(auto& set:sets) q+=(set.find(val) != set.end());
            if(q>=2) ans.push_back(val);
        }
        return ans;
        
    }
};
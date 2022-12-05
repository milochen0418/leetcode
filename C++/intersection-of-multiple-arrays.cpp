class Solution {
    //https://leetcode.com/problems/intersection-of-multiple-arrays
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_set<int> total;
        for(auto &v:nums)
            for(auto &i:v) 
                total.insert(i);
        
        vector<unordered_set<int>> nsets = vector<unordered_set<int>>(n,unordered_set<int>());
        for(int i = 0; i<n;i++) {
            for(auto &val:nums[i]) {
                nsets[i].insert(val);
            }
        }
        
        vector<int> ans;
        for(auto& a:total) {
            int in_all = 1;
            for(int i = 0; i<n;i++) {
                if(nsets[i].find(a) == nsets[i].end()) {
                    in_all = 0;
                    break;
                }
            }
            if(in_all) ans.push_back(a);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
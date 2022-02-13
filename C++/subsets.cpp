class Solution {
    // https://leetcode.com/problems/subsets/
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> v;
        for(auto& i:nums) s.insert(i);
        for(auto& i:s) v.push_back(i);
        
        int n = v.size();
        vector<vector<int>> result;
        int max_val = (int)pow(2,n);
        for(int i =0;i<max_val;i++) {
            vector<int> vv;
            for(int j=0;j<n;j++) {
               if( (i & (1<<j)) > 0) {
                  vv.push_back(v[j]);
               }
            }
            result.push_back(vv);
        }
        return result;
    }
};
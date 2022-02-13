class Solution {
    // https://leetcode.com/problems/subsets/
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>& v= nums;
        int n = v.size();        
        int max_val = (int)pow(2,n);
        vector<vector<int>> result(max_val, vector<int>());
        for(int i =0;i<max_val;i++) {
            for(int j=0;j<n;j++) {
               if( (i & (1<<j)) > 0) {
                   result[i].push_back(v[j]);
               }
            }
        }
        return result;   
    }
};
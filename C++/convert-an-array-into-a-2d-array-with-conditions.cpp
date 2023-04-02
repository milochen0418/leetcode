class Solution {
    //https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        int m = 0; //number of row
        for(auto &i:nums) {
            mp[i]++;
            m = max(m,mp[i]);
        }
        vector<vector<int>> ans;
        for(int i = 1;i<m+1;i++) {
            vector<int> v;
            for(auto &[val,cnt]:mp) {
                if(i<=cnt) v.push_back(val);
            }
            ans.push_back(v);
        }
        return ans;
        
    }
};
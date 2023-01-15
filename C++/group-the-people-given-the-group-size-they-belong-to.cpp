class Solution {
    //https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to
    //article https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/discuss/3055208/C%2B%2B-O(N)-array-with-hash-map
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,int> mp;
        for(auto &i:groupSizes) mp[i]++;
        
        unordered_map<int, vector<vector<int>>> amp;
        unordered_map<int, int> amp_idx;
        
        for(auto &[k,v]: mp) 
            amp[k] = vector<vector<int>>(mp[k]/k, vector<int>(k,0));
        
        
        for(int i = 0; i<groupSizes.size(); i++) {
            int k = groupSizes[i];
            int idx = amp_idx[k]++;
            amp[k][idx/k][idx%k] = i;
        }
        
        vector<vector<int>> ans;
        for(auto&[k,vv]: amp)
            for(auto &v:vv)
                ans.push_back(v);
        return ans;
        
    }
};
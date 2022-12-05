class Solution {
    //https://leetcode.com/problems/merge-similar-items
    //article https://leetcode.com/problems/merge-similar-items/discuss/2879220/C%2B%2B-or-9-lines-or-Hash-Map-or-Simple
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int,int> mp1, mp2, mpa;
        for(int i = 0; i<items1.size();i++) mp1[items1[i][0]] = items1[i][1];
        for(int i = 0; i<items2.size();i++) mp2[items2[i][0]] = items2[i][1];
        for(auto &[k,v]:mp1) mpa[k]+=v;
        for(auto &[k,v]:mp2) mpa[k]+=v;
        vector<vector<int>> ans;
        for(auto &[k,v]:mpa) ans.push_back({k,v});
        sort(ans.begin(), ans.end(), [](auto&lhs, auto&rhs){return lhs[0]<rhs[0];});
        return ans;
    }
};
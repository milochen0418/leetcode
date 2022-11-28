class Solution {
    //https://leetcode.com/problems/find-players-with-zero-or-one-losses
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;
        vector<vector<int>> ans = vector<vector<int>>(2,vector<int>());
        for(auto &m : matches) mp[m[0]] = mp[m[1]] = 0;
        for(auto &m : matches) mp[m[1]]++;
        for(auto &[p,lose] : mp) if(lose<=1) ans[lose].push_back(p);
        for(int i = 0;i<2;i++) sort(ans[i].begin(), ans[i].end());
        return ans;
    }
};
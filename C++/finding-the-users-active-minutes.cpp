class Solution {
    //https://leetcode.com/problems/finding-the-users-active-minutes
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans = vector<int>(k,0);
        unordered_map<int, unordered_set<int>> uam;
        for(auto &l :logs) {
            int id = l[0], time = l[1];
            uam[id].insert(time);
        }
        for(auto &[k,s]: uam) ans[s.size()-1]++;
        return ans;
    }
};
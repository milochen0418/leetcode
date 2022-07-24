class Solution {
    //https://leetcode.com/problems/time-needed-to-inform-all-employees
    //article https://leetcode.com/problems/time-needed-to-inform-all-employees/discuss/2327950/C%2B%2B-or-DFS
public:
    int ans = INT_MIN;
    int tmp;
    unordered_map<int, vector<int>> mp;//manager to each subordination
    vector<int>* pInformTime;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        pInformTime = &informTime;
        for(int i = 0; i<manager.size();i++) mp[manager[i]].push_back(i);
        tmp = 0;
        dfs(headID);        
        return ans;
    }
    void dfs(int i) {
        vector<int>& informTime = *pInformTime;
        if(mp.find(i) == mp.end()) {
            ans = max(ans, tmp);
        } else {
            tmp+=informTime[i];
            for(auto&c: mp[i]) dfs(c);
            tmp-=informTime[i];
        }
    }
};
class Solution {
    //https://leetcode.com/problems/reachable-nodes-with-restrictions
public:
    unordered_set<int> limited;
    unordered_map<int,vector<int>> mp;
    
    int ans = -1;
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        for(auto &i: restricted) limited.insert(i);
        for(auto& e:edges) {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        dfs(0);
        if(ans==0) ans=1;
        return ans;
    }
    void dfs(int root) {
        ans++;
        for(auto &child: mp[root]) {
            if(limited.find(child) == limited.end()) {
                limited.insert(child);
                dfs(child);
            }
        }
    }
};
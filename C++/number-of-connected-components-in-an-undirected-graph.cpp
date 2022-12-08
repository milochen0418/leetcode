class Solution {
    //https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph
public:
    unordered_map<int,vector<int>> mp;
    unordered_set<int> travelled;
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        
        for(auto &e: edges) {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        for(int i = 0; i<n;i++) {
            if(travelled.find(i) == travelled.end()) {
                ans++;
                travelled.insert(i);
                dfs(i);
            }
        }
        return ans;
    }
    void dfs(int root) {
        for(auto& i: mp[root]) {
            if(travelled.find(i) == travelled.end()) {
                travelled.insert(i);
                dfs(i);
            }
        }
    }
};
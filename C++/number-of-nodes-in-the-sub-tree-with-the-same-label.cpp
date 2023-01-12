class Solution {
    //https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label
public:
    unordered_map<int, vector<int>> mp;
    vector<vector<int>> res;
    vector<int> empty_feature;
    vector<bool> visited;
    string labels;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labelss) {
        labels = labelss;
        res=vector<vector<int>>(n,vector<int>(26,0));
        visited = vector<bool>(n,false);
        for(auto &e: edges) {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        dfs(0);
        
        vector<int> ans = vector<int>(n,0);
        for(int i = 0; i<n;i++)  ans[i] = res[i][labels[i]-'a'];
        return ans;
    }
    
    
    void dfs(int root) {
        visited[root] = true;
        res[root][labels[root]-'a']++;
        for(auto &child: mp[root]) {
            if(visited[child] == false) {
                dfs(child);
                for(int i = 0;i<26;i++) res[root][i]+=res[child][i];
            }
        }
    }
    
    
};
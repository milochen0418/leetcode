class Solution {
    //https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label
    //article https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/discuss/3038318/C%2B%2B-DFS-explanation
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/6032768313412276/
public:
    unordered_map<int, vector<int>> mp;
    vector<vector<int>> extend;
    vector<bool> visited;
    string labels;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labelss) {
        labels = labelss;
        extend=vector<vector<int>>(n,vector<int>(26,0));
        visited = vector<bool>(n,false);
        for(auto &e: edges) {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        dfs(0);
        vector<int> ans = vector<int>(n,0);
        for(int i = 0; i<n;i++)  ans[i] = extend[i][labels[i]-'a'];
        return ans;
    }

    void dfs(int root) {
        visited[root] = true;
        extend[root][labels[root]-'a']++;
        for(auto &child: mp[root]) {
            if(visited[child] == false) {
                dfs(child);
                for(int i = 0;i<26;i++) extend[root][i]+=extend[child][i];
            }
        }
    }
};
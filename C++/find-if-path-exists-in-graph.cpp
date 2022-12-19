class Solution {
    //https://leetcode.com/problems/find-if-path-exists-in-graph
    //article https://leetcode.com/problems/find-if-path-exists-in-graph/discuss/2927026/C%2B%2B-or-DFS-or-improve
public:
    vector<vector<int>> E;
    vector<int> travelled;
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {    
        E = vector<vector<int>>(n, vector<int>());
        travelled = vector<int>(n,0);
        for(auto &e:edges) {
            E[e[0]].push_back(e[1]);
            E[e[1]].push_back(e[0]);
        }
        dfs(source);
        if(travelled[destination]==0) return false;
        return true;
        
    }
    void dfs(int source) {
        travelled[source] = 1;
        for(auto &i:E[source]) {
            if(travelled[i]==0) {
                dfs(i);
            }
        } 
    }
};
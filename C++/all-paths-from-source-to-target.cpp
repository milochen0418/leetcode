class Solution {
    //https://leetcode.com/problems/all-paths-from-source-to-target
public:
    vector<vector<int>> ans, *pGraph;
    vector<int> path;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        pGraph = &graph;
        dfs(0);
        return ans;
    }
    void dfs(int root) {
        path.push_back(root);
        if(path.back() == pGraph->size()-1) 
            ans.push_back(path);
        else
            for(auto &i: (*pGraph)[root]) dfs(i);
        path.pop_back();
    }
};
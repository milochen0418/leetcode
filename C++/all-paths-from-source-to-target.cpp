class Solution {
    //https://leetcode.com/problems/all-paths-from-source-to-target
public:
    vector<vector<int>>* pGraph;
    vector<vector<int>> ans;
    vector<int> tmp; //temp vector in dfs.
    int t; // target
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        pGraph = &graph;
        t = n-1;
        dfs(0);
        return ans;
    }
    void dfs(int s) {
        tmp.push_back(s);
        if(s == t) ans.push_back(tmp);
        for(auto& next_s: (*pGraph)[s]) dfs(next_s);
        tmp.pop_back();
    }
};
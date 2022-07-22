class Solution {
    //https://leetcode.com/problems/number-of-provinces
public:
    vector<vector<int>>* pG;
    unordered_set<int> s;
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        pG = &isConnected;
        int n = isConnected.size();
        int ans = 0;
        for(int i = 0; i<n;i++) {
            if(s.find(i)==s.end()){
                s.insert(i);
                ans++;
                dfs(i);
            }
        }
        return ans;
    }
    void dfs(int i) {
        vector<vector<int>>&g = *pG;
        for(int j=0;j<g.size();j++){
            if(g[i][j]==1) {
                if(s.find(j) == s.end()) {
                    s.insert(j);
                    dfs(j);
                }
            }
        }
    }
};
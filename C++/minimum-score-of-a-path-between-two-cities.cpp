class Solution {
    //https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
    //article : https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/discuss/2875363/C%2B%2B-or-simple-DFS-or-easy-or-O(N)
public:
    unordered_set<int> s;
    unordered_map<int, vector<int>> mp;
    int minScore(int n, vector<vector<int>>& roads) {
        //[[1,2,9],[2,3,6],[2,4,5],[1,4,7]]  BFS to find all edge from 1. and find out the minimum edge
        
        for(auto& r:roads) {
            mp[r[0]].push_back(r[1]);
            mp[r[1]].push_back(r[0]);
        }
        dfs(1);
        //s is the connected vertex with 1 and n now.
        
        //find out the minimum edge in connected vertice that including 1 & n;
        int ans = INT_MAX;
        for(auto& r:roads) {
            if(s.find(r[0]) != s.end()) {
                ans = min(ans, r[2]);
            }
        }
        return ans;
        
    }
    void dfs(int root) {
        if(s.find(root) != s.end()) return;
        s.insert(root);
        for(auto&child : mp[root]) {
            dfs(child);
        }
    }
};
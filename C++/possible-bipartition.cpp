class Solution {
    //https://leetcode.com/problems/possible-bipartition
    //article https://leetcode.com/problems/possible-bipartition/discuss/2934048/C%2B%2B-or-use-DFS-with-BFS-to-solve
public:
    unordered_map<int, vector<int>> mp;
    unordered_set<int> dfs_visited; 
    unordered_set<int> bfs_visited; 
    unordered_set<int> roots; 
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(auto &v:dislikes) {
            mp[v[0]].push_back(v[1]);
            mp[v[1]].push_back(v[0]);
        }
           
        for(int i = 1;i<=n;i++) {
            if(dfs_visited.find(i) == dfs_visited.end()) {
                roots.insert(i);
                dfs(i);    
            }
        }
        
        for(auto &root: roots) {
            queue<int> currQ;
            queue<int> nextQ;
            unordered_set<int> curr_level_nodes;
            unordered_set<int> next_level_nodes;            
            currQ.push(root);
            curr_level_nodes.insert(root);
            
            bfs_visited.insert(root);            
            while(!currQ.empty()) {
                int e = currQ.front();
                currQ.pop();
                for(auto &i:mp[e]) {
                    if(curr_level_nodes.find(i) != curr_level_nodes.end()) return false;                
                    if(bfs_visited.find(i) != bfs_visited.end()) continue;
                    nextQ.push(i);
                    next_level_nodes.insert(i);
                    bfs_visited.insert(i);
                }
                
                if(currQ.empty()) {
                    swap(currQ, nextQ);
                    //level_nodes change
                    swap(next_level_nodes, curr_level_nodes);
                    next_level_nodes.clear();
                }
            }
        }
        return true;
    }
    void dfs(int root) {
        dfs_visited.insert(root);
        for(auto &i:mp[root]) {
            if (dfs_visited.find(i) == dfs_visited.end()) {
                dfs(i);
            }
        }
    }
};
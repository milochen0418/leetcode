class Solution {
    //https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/
    //article :https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/discuss/2876332/C%2B%2B-or-DFS-%2B-BFS-or-easy-or-explanation
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5909531602402615/
public:
    unordered_map<int, unordered_set<int>> mp;
    vector<unordered_set<int>> graphs_V;
    unordered_set<int> travelled;//dfs travelled vertics.
    int magnificentSets(int n, vector<vector<int>>& edges) {
        int ans = 0; // find out the maximum BFS level
        
        for(int i = 0; i < edges.size();i++) {
            mp[edges[i][0]].insert(edges[i][1]);
            mp[edges[i][1]].insert(edges[i][0]);
        }
        
        for(int i = 1; i<=n;i++) {
            if(travelled.find(i) == travelled.end()) {
                
                unordered_set<int> V;
                dfs(i,V);
                graphs_V.push_back(V);
            }    
        }
        for(unordered_set<int> &vertice: graphs_V) {            
            int ret = try_bfs_of_graph(vertice);
            if(ret==-1) return -1;
            ans += ret;
        }
        
        return ans;
        
    }
    void dfs(int u, unordered_set<int>& vertice) {
        vertice.insert(u);
        travelled.insert(u);
        for(auto&v:mp[u]) {
            if(travelled.find(v) == travelled.end()) {
                dfs(v, vertice);
            }
        }
    }
    
    int try_bfs_of_graph(unordered_set<int>& graphV) {
        int ans = -1;
        vector<int> graphVv;
        for(auto &i:graphV) {
            graphVv.push_back(i);
        }
        sort(graphVv.begin(), graphVv.end(), [&](auto &lhs, auto& rhs){
            if(mp[lhs].size() == mp[rhs].size()) {
                return lhs<rhs;
            } else {
                return mp[lhs].size() < mp[rhs].size();    
            }
        });
        
        vector<int> graphVvv;
        for(auto &i:graphVv) {
            if(mp[graphVv[0]].size()==mp[i].size()) {
                graphVvv.push_back(i);
            }
        }
        
        //for(auto &i:graphV){
        for(auto &i:graphVvv){
            //Changing to use the graphVvv to instead graphV is 
            //the magic stuff to against TLE XD
            queue<int> currQ;
            queue<int> nextQ;
            unordered_set<int> s;
            s.insert(i);
            currQ.push(i);
            int len = 0;
            unordered_set<int> ls;//the vertex set in the same level
            while(!currQ.empty()) {
                int e = currQ.front();
                currQ.pop();
                for(auto&v: mp[e]) {
                    
                    if(s.find(v) == s.end()) {
                        s.insert(v);
                        ls.insert(v);
                        nextQ.push(v);
                    }
                }
                if(currQ.empty()) {                    
                    len++;
                    int is_break = 0;
                    for(auto &x : ls) {
                        for(auto &y: mp[x]) {
                            if(ls.find(y) != ls.end()) {
                                is_break = 1;
                                len = -1;
                                break;
                            }
                        }
                        if(is_break) break;
                    }
                    if(is_break) break;
                    ls.clear();
                    swap(currQ,nextQ);
                }
            }
            ans = max(ans, len);
        }
        return ans;
    }    
};
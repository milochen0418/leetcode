class Solution {
    //https://leetcode.com/problems/number-of-operations-to-make-network-connected
    unordered_map<int, vector<int>> g;
    unordered_set<int> s;
    int set_max = 0;
    
public:
    /*
    Observation 
    Assume c is the number of component in this graph.
    We at least need c-1 times to change edge, so that all vertex will be in the same component.
    The graph G need to have the at least n-1 edge to become tree. 
    If the number of edge is less than n-1 in graph, than you can never find out the way
    to move edge to let graph become one component.
    */
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        for(auto &e: connections) {
            if(g.find(e[0]) == g.end()) g[e[0]] = vector<int>();
            g[e[0]].push_back(e[1]);
            if(g.find(e[1]) == g.end()) g[e[1]] = vector<int>();
            g[e[1]].push_back(e[0]);
        }
        
        int c=0;//number of component 
        
        set_max = n-g.size();
        c+=set_max;
        
        for(auto &[u, vs]: g) {
            if(s.find(u)==s.end()) {
                s.insert(u);
                c=c+1;
                if(set_max == s.size()) break;
                dfs(u);
            }
            
        }
        //printf("c=%d, g.size()=%d, n = %d\n",c, g.size(),n );
        
        return c-1;
        //return 0;
    }
    
    void dfs(int i) {
        for(auto &u: g[i]) {
            if(s.find(u)==s.end()) {
                s.insert(u);
                dfs(u);
                if(set_max == s.size()) break;
            }
        }
    }
};
class Solution {
    //https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        /*
        Idea 
        (1) convert connections in into two map mpuv & mpvu e.g. 
        [u=3,v=2]  can make mpuv[3] = 2 and mpvu[2] = 3
        (2) Use BFS can run the code from 0 to every node by mpuv and mpvu.
        But count up the ans if it use the edge mpuv[u]=v to travel and
        don't count up the ans if it use the edge mpvu[v]=u to travel. 
        */
        unordered_map<int,unordered_set<int>> mpuv;
        unordered_map<int,unordered_set<int>> mpvu;
        
        for(auto &e: connections) {//e=[u,v]
            mpuv[e[0]].insert(e[1]);
            mpvu[e[1]].insert(e[0]);
        }
        
        int ans = 0;
        unordered_set<int> s;
        queue<int> Q;
        Q.push(0);
        s.insert(0);
        while(!Q.empty()) {
            int e = Q.front();
            Q.pop();
            for(auto v: mpuv[e]) {
                if(s.find(v) == s.end()) {
                    ans++;
                    Q.push(v);
                    s.insert(v);                    
                }
            }
            for(auto u: mpvu[e]) {
                if(s.find(u) == s.end()) {
                    Q.push(u);
                    s.insert(u);
                }
            }
        }
        return ans;
    }
};
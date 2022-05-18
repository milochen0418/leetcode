class Solution {
    //https://leetcode.com/problems/critical-connections-in-a-network/
public:
    struct edge{int u; int v;};//edge from u to v 
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //Test case 10/17 is not pass https://leetcode.com/submissions/detail/702179235/
        vector<vector<int>> ans;
        unordered_map<int,unordered_set<int>> emp;
        for(auto &e:connections) {
            emp[e[0]].insert(e[1]);
            emp[e[1]].insert(e[0]);
        }
        unordered_set<int> s;//travelled set
        
        queue<int> currQ;
        queue<int> nextQ;
        currQ.push(0);
        s.insert(0);
        
        while(!currQ.empty()) {
            //unordered_map<int,int> tmp;//temp set
            
            unordered_set<int> tsOne;
            unordered_set<int> tsMore;
            unordered_set<int> nextSet;
            //unordered_map<int,int> critical_edges;
            vector<edge> critical_edges = vector<edge>();
            
            while(!currQ.empty()) {
                int u = currQ.front();    
                currQ.pop();

                printf("adj(u=%d):\n",u);
                for(auto& v: emp[u]) {
                    printf("(u,v)= (%d,%d)\n",u,v);
                }
                
                
                for(auto& v: emp[u]) {
                    if(s.find(v) == s.end()) {
                        
                        
                        if(tsOne.find(v) == tsOne.end()) {
                            tsOne.insert(v);
                            nextQ.push(v);
                            nextSet.insert(v);
                            printf("set (u,v)= (%d,%d) in critical_edges\n",u,v);
                            critical_edges.push_back(edge{u,v});
                            //critical_edges[u]=v;
                        } else {
                            tsMore.insert(v);                                
                        }
                    } 
                }
            }
            printf("critical_edges:\n");
            //for(auto &[u,v]:critical_edges) {
            for(const edge& e:critical_edges) {
                //printf("(u,v)= (%d,%d)\n",u,v);
                printf("(u,v)= (%d,%d)\n",e.u,e.v);
            }

            
            unordered_map<int,int> cntMap;
            for(auto&i: nextSet) {
                for(auto&j: emp[i]) {
                    if(nextSet.find(j) != nextSet.end()) {
                        cntMap[i]++;
                    }
                }
            }
            for(auto &[key,val]:cntMap) {
                printf("(k,v)= (%d,%d)\n",key,val);
            }
            
            //for(auto &[u,v]:critical_edges) {
            for(auto &e:critical_edges) {            
                //printf("(u,v, cntMap[v])= (%d,%d,%d)\n",u,v,cntMap[v]);
                printf("(u,v, cntMap[v])= (%d,%d,%d)\n",e.u,e.v,cntMap[e.v]);
                //if(tsMore.find(v) == tsMore.end()) {
                if(tsMore.find(e.v) == tsMore.end()) {                
                    //if((cntMap[v]==0)) {
                    if((cntMap[e.v]==0)) {
                        vector<int> sol = vector<int>(2,0);
                        sol[0] = e.u; sol[1] = e.v;
                        ans.push_back(sol);                        
                    }
                }
            }
            
            for(auto &i:tsOne) s.insert(i);
            
                
            
            if(nextQ.empty()) {
                break;
            } else {
                swap(currQ,nextQ);
            }
        }
        return ans;
        
    }

    vector<vector<int>> criticalConnectionsTimeLimitExceeded(int n, vector<vector<int>>& connections) {
        //Test case 09/17 TimeLimitExceeded
        vector<vector<int>> ans;
        vector<vector<int>>& es = connections;
        unordered_map<int,vector<int>> mp;
        for(vector<int>& e:es){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        
        for(int i = 0; i<es.size(); i++) {
            vector<int>& e = es[i];
            unordered_set<int> s;
            queue<int> q;
            int cnt = 0;
            q.push(e[0]);
            cnt++;
            s.insert(e[0]);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(auto &v: mp[u]) {
                    if(u==e[0] && v==e[1]) continue;
                    if(u==e[1] && v==e[0]) continue;
                    if(s.find(v) != s.end()) continue;
                    s.insert(v);
                    q.push(v);
                    cnt++;
                }
            }
            if(cnt<n) {
                ans.push_back(e);
            }
        }
        return ans;
    }
};
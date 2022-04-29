class Solution {
    //https://leetcode.com/problems/is-graph-bipartite
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<queue<int>>  qs =  vector<queue<int>> (2,queue<int>());
        vector<int> travel= vector<int>(n,-1) ; //-1:not travel,0:belong part 0, 1: belong part 1 
        
        int q_idx = 0;
        qs[q_idx].push(0);
        travel[0] = q_idx;
        
        while(!qs[q_idx].empty()) {
            int next_q_idx = (q_idx+1)%2;
            queue<int>& curr_q = qs[q_idx];
            queue<int>& next_q = qs[next_q_idx];
            int vertex = curr_q.front();
            curr_q.pop();
            vector<int>& adj = graph[vertex];
            for(auto&i: adj) {
                if(travel[i] == -1){
                    travel[i] = next_q_idx;
                    next_q.push(i);                    
                } else {
                    if(travel[i] == travel[vertex]) {
                        return false;
                    }   
                }
            }
            q_idx = next_q_idx;
            if(qs[q_idx].empty()) {
                //empty() because there might be some component independent to current component 
                //so find it and put it in queue
                for(int i=0;i<n;i++){
                    if(travel[i]==-1) {
                        qs[q_idx].push(i);
                        travel[i] = q_idx;
                        break;
                    }
                }
            }
        }
        
        return true;
    }
};
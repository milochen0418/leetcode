class Solution {
    //https://leetcode.com/problems/is-graph-bipartite/
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<queue<int>>  qs =  vector<queue<int>> (2,queue<int>());
        vector<int> travel= vector<int>(n,-1) ; //-1:not travel,0:belong part 0, 1: belong part 1 
        
        int q_idx = 0;
        qs[q_idx].push(0);
        travel[0] = q_idx;
        int nontravel_idx = 1;
        
        while(!qs[q_idx].empty()) {
            int next_q_idx = (q_idx+1)%2;
            int vertex = qs[q_idx].front();
            qs[q_idx].pop();
    
            vector<int>& adj = graph[vertex];
            for(auto&i: adj) {
                if(travel[i] == -1){
                    travel[i] = next_q_idx;
                    qs[next_q_idx].push(i);                    
                } else if(travel[i] == travel[vertex]) {
                    return false; 
                }
            }
            if(qs[next_q_idx].empty()) {
                //find next indepedent component if it is exist. 
                for(int i=nontravel_idx;i<n;i++) {
                    if(travel[i]==-1) {
                        qs[next_q_idx].push(i);
                        travel[i] = next_q_idx;
                        nontravel_idx = i+1;
                        break;
                    }
                }
            }
            q_idx = next_q_idx;
        }
        return true;
    }
};
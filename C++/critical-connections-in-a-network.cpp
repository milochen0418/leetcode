class Solution {
    //https://leetcode.com/problems/critical-connections-in-a-network/
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
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
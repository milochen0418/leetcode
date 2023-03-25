class Solution {
    //https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph
public:
    typedef long long ll;
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mp;
        for(auto &e:edges) {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        int count = 0;
        vector<int> visited = vector<int>(n,0);
        function<void(int)> dfs =[&](int i) {
            count++;
            visited[i] = 1;
            for(auto &j: mp[i]) if(visited[j]==0) dfs(j);
        };
        vector<int>v;
        for(int i = 0; i<n; i++) {
            if(visited[i] == 0) {
                count = 0;
                dfs(i);
                v.push_back(count);
            }
        }
        ll ans = 0;
        for(auto &i:v) ans += (ll)(i)*(ll)(n-i);
        return ans/2;
    }
};
class Solution {
    //https://leetcode.com/problems/count-the-number-of-complete-components/
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mp;
        for(auto &e: edges) {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        int j = 0; //j'th component
        vector<vector<int>> comps;
        
        vector<int> visited = vector<int>(n,0);
        
        function<void(int)> dfs = [&](int root){
            comps.back().push_back(root);
            visited[root] = 1;
            for(auto &v:mp[root]) {
                if(visited[v] == 0) {
                    dfs(v);
                }
            }
        };
        
        
        
        for(int i = 0; i<n; i++) {
            if(visited[i] == 0) {
                comps.push_back(vector<int>());
                dfs(i);
                j++;
            }
        }
        /*
        printf("\n\n");
        for(int i = 0; i<j;i++) {
            for(auto v: comps[i]) {
                printf("%d,", v);
            }
            printf("\n");
        }*/
        //return j;
        
        int ans = 0;
        for(int i = 0; i<j;i++) {
            int is_completed = 1;
            for(auto v: comps[i]) {
                if (mp[v].size() != comps[i].size()-1) {
                    is_completed = 0;
                    break;
                }
            }
            ans+=is_completed;
        }
        return ans;
    }
};
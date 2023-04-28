class Solution {
    //https://leetcode.com/problems/similar-string-groups
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> vs=vector<vector<int>>(n, vector<int>(26,0));
        for(int i = 0;i<n;i++) for(auto &c:strs[i]) vs[i][c-'a']++;
        function<bool(int, int)> similar = [&](int i, int j){
            int sum = 0;
            if(strs[i].length() != strs[j].length()) return false;
            if(vs[i] != vs[j]) return false;
            int m = strs[i].length();
            int cnt=0;
            for(int k=0;k<m;k++) 
                if(strs[i][k] != strs[j][k]) 
                    if(++cnt>2) return false;
            return true;
        };

        unordered_map<int,vector<int>> mp;//edges
        for(int i = 0;i<n;i++) 
            for(int j = i+1;j<n;j++) 
                if(similar(i,j)==true) {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                    //printf("similar(%d,%d)\n",i,j);
                }
        
        vector<int> visited = vector<int>(n,0);
        function<void(int)> dfs = [&](int root) {
            visited[root] = 1;
            for(auto &child:mp[root]) 
                if(visited[child]==0) dfs(child);
        };
        int ans = 0;
        for(int i = 0;i<n;i++) {
            if(visited[i] == 0) {
                ans++;
                dfs(i);
            }
        }
        return ans;
    }
    
};
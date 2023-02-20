class Solution {
    //https://leetcode.com/problems/accounts-merge/
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<int>> mp;//email to index
        int n = accounts.size();
        for(int i = 0; i<n;i++) {
            vector<string> &acc = accounts[i];
            for(int j =1;j<acc.size();j++) {
                mp[acc[j]].push_back(i);
            }
        }
        unordered_map<int, string> mptoname;//mapping of index of accounts to its account name
        for(int i = 0;i<n;i++) mptoname[i]=accounts[i][0];
        
        
        vector<vector<string>> ans = vector<vector<string>>();
        
        function<void(int)> dfs = [&](int i){
            
        };
        for(int i=0;i<n;i++) {
            dfs(i);
        }
        
        return ans;
    }
};
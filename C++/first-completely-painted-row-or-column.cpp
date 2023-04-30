class Solution {
    //https://leetcode.com/problems/first-completely-painted-row-or-column/
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row_cnt = vector<int>(m,0); //find out answer when row_cnt >= n
        vector<int> col_cnt = vector<int>(n,0); //find pout answer when col_cnt>=m
        vector<unordered_set<int>> row_sets = vector<unordered_set<int>>(m,unordered_set<int>());
        vector<unordered_set<int>> col_sets = vector<unordered_set<int>>(n,unordered_set<int>());
        
        unordered_map<int, int> row_mp; //matrix value to index of row_sets
        unordered_map<int, int> col_mp; //matrix value to index of col_sets
        
        for(int i = 0; i<m;i++) {
            for(int j = 0;j<n;j++) {
                row_mp[mat[i][j]] = i;
                col_mp[mat[i][j]] = j;
                row_sets[i].insert(mat[i][j]);
                col_sets[j].insert(mat[i][j]);
            }
        }
        
        int ans = 0;
        for(auto &i:arr) {
            if(row_sets[row_mp[i]].find(i) != row_sets[row_mp[i]].end()) row_cnt[row_mp[i]]++;
            if(col_sets[col_mp[i]].find(i) != col_sets[col_mp[i]].end()) col_cnt[col_mp[i]]++;
            if(row_cnt[row_mp[i]]>=n || col_cnt[col_mp[i]]>=m) return ans;
            ans++;
        }
        return m*n-1;
        
    }
};
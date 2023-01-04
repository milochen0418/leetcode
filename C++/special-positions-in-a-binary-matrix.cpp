class Solution {
    //https://leetcode.com/problems/special-positions-in-a-binary-matrix
    //article https://leetcode.com/problems/special-positions-in-a-binary-matrix/discuss/2998607/C%2B%2B-Two-Pass-O(M*N)
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<unordered_set<int>> col_sets=vector<unordered_set<int>>(n,unordered_set<int>());
        vector<unordered_set<int>> row_sets=vector<unordered_set<int>>(m,unordered_set<int>());
            
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(mat[i][j]) {
                    row_sets[i].insert(j);
                    col_sets[j].insert(i);
                }
            }
        }
        
        int ans = 0;
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(mat[i][j]==1) {
                    ans+= ((row_sets[i].size()==1) && ((col_sets[j].size()==1)));
                }
            }
        }
        return ans;
    }
};
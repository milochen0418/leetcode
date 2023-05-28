class Solution {
    //https://leetcode.com/problems/difference-of-number-of-distinct-values-on-diagonals/
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans = vector<vector<int>>(m, vector<int>(n,0));
        
        for(int r = 0; r<m; r++) {
            for(int c = 0; c<n; c++) {
                unordered_set<int> brs;
                unordered_set<int> lts;
                int i,j;
                i = r+1;
                j = c+1;
                while(i<m && j<n) {
                    brs.insert(grid[i++][j++]);
                }
                
                i=r-1;
                j=c-1;
                while(i>=0 && j>=0) {
                    lts.insert(grid[i--][j--]);
                }
                
                ans[r][c] = abs((int)lts.size() - (int)brs.size());
            }
        }
        return ans; 
    }
};
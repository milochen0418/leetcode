class Solution {
    //https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rowOne = vector<int>(m, 0), colOne = vector<int>(n,0);
        vector<int> rowZero = vector<int>(m, 0), colZero = vector<int>(n,0);
        for(int j = 0; j<n; j++) {
            for(int i = 0;i<m; i++) {
                colOne[j]+= (grid[i][j] == 1);
            }
            colZero[j] = m - colOne[j];
        }
        for(int i = 0;i<m; i++) {
            for(int j = 0; j<n; j++) {
                rowOne[i]+= (grid[i][j] == 1);
            }
            rowZero[i] = n - rowOne[i];
        }
        
        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++)
                grid[i][j] = rowOne[i] + colOne[j] - rowZero[i] - colZero[j];
        return grid;
    }
};
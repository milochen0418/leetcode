class Solution {
    //https://leetcode.com/problems/shift-2d-grid
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans = grid;
        int rows = grid.size();
        int cols = grid[0].size();
        int n = rows*cols; 
        for(int i = 0; i < n;i++) { 
            int next = (i+k)%n;
            pair<int,int> curr_coor = get2D(i, rows, cols);
            pair<int,int> next_coor = get2D(next, rows, cols);
            ans[next_coor.first][next_coor.second] = grid[curr_coor.first][curr_coor.second];
        }
        return ans;
    }
    
    pair<int,int> get2D(int i, int rows, int cols){
        return {i/cols, i%cols};
    }
    int get1D(pair<int,int> p, int rows, int cols) {
        int row = p.first;
        int col = p.second;
        return row * cols + col;
    }
};
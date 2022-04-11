class Solution {
    //https://leetcode.com/problems/shift-2d-grid
public:
    vector<vector<int>>& shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size(), n = rows*cols; 
        int r = gcd(n,k);
        for(int i = 0; i<r;i++) {
            int temp = grid[i/cols][i%cols];
            int curr_idx = i;
            for(int j = 0;j<n/r;j++) {
                int next_idx = (curr_idx+k)%n;
                int prev_temp = temp;
                temp = grid[next_idx/cols][next_idx%cols];
                grid[next_idx/cols][next_idx%cols] = prev_temp;
                curr_idx = next_idx;
            }
        } 
        return grid;
    }    
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int rows = gcd(n, k);
        for(int i = 0; i < rows; i++) {
			//seperate into gcd(n,k) rows cases
            int temp = nums[i];
            int curr_idx = i;                
            for(int j = 0 ; j < n / rows; j++) {
				//Make a rorated move for each row by two temp
                int next_idx = (curr_idx + k) % n;
                int prev_temp = temp;
                temp = nums[next_idx];
                nums[next_idx] = prev_temp;
                curr_idx = next_idx;
            }
        }
    }

    vector<vector<int>> answer1(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans = grid;
        int rows = grid.size(), cols = grid[0].size(), n = rows*cols; 
        for(int curr = 0; curr < n;curr++) { 
            int next = (curr+k)%n;
            ans[next/cols][next%cols]= grid[curr/cols][curr%cols];
        }
        return ans;
    }    

};
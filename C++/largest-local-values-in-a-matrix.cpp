class Solution {
    //https://leetcode.com/problems/largest-local-values-in-a-matrix
    //article https://leetcode.com/problems/largest-local-values-in-a-matrix/discuss/2878868/C%2B%2B-or-O(N2)
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans = vector<vector<int>>(grid.size()-2, vector<int>(grid.size()-2,0));
        for(int i = 0; i<ans.size();i++ ) 
            for(int j = 0; j<ans.size();j++) 
                for(int k = 0;k<9;k++) 
                    ans[i][j] = max(ans[i][j], grid[i+k/3][j+k%3]);
        return ans;
    }
};
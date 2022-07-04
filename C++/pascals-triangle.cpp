class Solution {
    //https://leetcode.com/problems/pascals-triangle
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = vector<vector<int>>(numRows, vector<int>(1,1));
        for(int i = 1; i<numRows;i++) {
            for(int j = 1;j<i; j++) {
                //printf("ans[i-1][j-1]=%d\n", ans[i-1][j-1]);
                //printf("ans[i-1][j]=%d\n", ans[i-1][j]);
                ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
                //ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
                //printf("ans[i][j]=%d\n", ans[i][j]);
            }
            ans[i].push_back(1);
        }
        return ans;
    }
};
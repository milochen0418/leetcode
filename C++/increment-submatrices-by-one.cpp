class Solution {
    //https://leetcode.com/problems/increment-submatrices-by-one/
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans = vector<vector<int>>(n, vector<int>(n,0));
        for(auto &q:queries) {
            for(int r = q[0]; r<=q[2];r++) {
                for(int c = q[1]; c<=q[3];c++) {
                    ans[r][c]++; 
                }    
            }
        }
        return ans;
    }
};
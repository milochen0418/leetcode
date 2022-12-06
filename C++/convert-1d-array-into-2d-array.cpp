class Solution {
    //https://leetcode.com/problems/convert-1d-array-into-2d-array
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n != original.size()) return {};
        vector<vector<int>> ans = vector<vector<int>>(m, vector<int>(n,0));
        for(int i = 0; i < original.size();i++) ans[i/n][i%n] = original[i];
        return ans;
    }
};
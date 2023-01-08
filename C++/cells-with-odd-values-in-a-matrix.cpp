class Solution {
    //https://leetcode.com/problems/cells-with-odd-values-in-a-matrix
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int ans =0;
        vector<int> rv = vector<int>(m,0), cv = vector<int>(n,0);
        for(auto &rc:indices) rv[rc[0]]++, cv[rc[1]]++;
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                ans+=(rv[i]+cv[j])%2;
        return ans;
    }
};
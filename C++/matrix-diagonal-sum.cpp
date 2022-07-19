class Solution {
    //https://leetcode.com/problems/matrix-diagonal-sum
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(); 
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans+=mat[i][i];
            ans+=mat[i][n-i-1];
        }
        if(n%2==1) ans-=mat[n/2][n/2];
        return ans;
    }
};
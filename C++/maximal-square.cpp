class Solution {
    //https://leetcode.com/problems/maximal-square/
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n=matrix[0].size();
        int k = min(m,n);
        vector<vector<vector<int>>> dp 
            = vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(k,-1)));
        int max_width = 0;
        for(int l = 0; l<k;l++) {
            for(int i=m-1;i>=0;i--) {
                for(int j=n-1;j>=0;j--) {
                    if(dp[i][j][l]!=-1)continue;
                    if(l==0) {
                        dp[i][j][l]=matrix[i][j]-'0';
                        if(dp[i][j][l]==0)
                            for(int q=l;q<k;q++) 
                                dp[i][j][q]=0;
                    } else {
                        if(i+1>=m || j+1>=n) {
                            dp[i][j][l] = 0;
                        } else if(dp[i][j+1][l-1] && dp[i+1][j][l-1] && dp[i+1][j+1][l-1]) {
                            dp[i][j][l] = 1;
                        } else {
                            dp[i][j][l] = 0;
                            for(int q=l;q<k;q++) 
                                dp[i][j][q]=0;
                        }
                    }
                    if(dp[i][j][l]) {
                        if(max_width<l+1) {
                            max_width =l+1;
                        }
                    }
                }
            }            
        }
        return max_width*max_width;
    }
};
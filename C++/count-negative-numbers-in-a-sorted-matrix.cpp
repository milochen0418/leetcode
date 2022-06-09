class Solution {
    //https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size();        
        int i = 0,j=n-1;
        int ans = 0;
        for(i = 0; i<m;i++){
            if(j<0||grid[i][j]<0) {
                while(j>0) {
                    if(grid[i][j-1]>=0) break;
                    j--;
                }                
                //printf("?i=%d -> %d\n",i, n-j);
                ans+=(n-j);
            }
        }
        return ans;
    }


    int countNegativesUgly(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size();        
        int i = 0,j=n-1;
        int ans = 0;
        for(i = 0; i<m;i++){
            if(j<0||grid[i][j]<0) {
                while(j>=0) {
                    if(grid[i][j]>=0) {
                        j=j+1;
                        //[9,8,7,6,5,0,-1,-2,-3] -> j=6, n=9, ans+=3
                        printf("i=%d -> %d\n",i, n-j);
                        ans += (n-j);
                        break;
                    }
                    j--;
                }
                if(j<0) {
                    printf("?i=%d -> %d\n",i, n);
                    ans+=n;
                }
            }else {
                printf("_i=%d -> %d\n",i, 0);
            }    
        }
        return ans;
    }
};
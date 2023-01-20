class Solution {
    //https://leetcode.com/problems/count-square-submatrices-with-all-ones
public:

    vector<vector<vector<int>>> cnt;
    //ones[r][c] = 2; mean there is no any zero element in marathon distance=2 , but start to have zero element in distance 3.     
    
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>>& M = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        /*
        int k = min(m,n);
        vector<vector<int>> cnt = vector<vector<int>>(m+1, vector<int>(n+1,k));
        for(int r = 0; r<m+1;r++) {
            for(int c =0;c<n+1;c++) {
                int ele = r>=m || c>=n ? 0 : M[r][c];
                if(ele == 1) continue;
                //O(K^2)
                cnt[r][c]=0;
                for(int d = 1; d<k;d++) {
                    int nr = r-d, nc=c-d;
                    if(nr>=0)
                        for(int col = max(0,nc);col<=c;col++) 
                            cnt[nr][col]=min(cnt[nr][col], d);
                    if(nc>=0)
                        for(int row = max(0,nr);row<=r;row++) 
                            cnt[row][nc]=min(cnt[row][nc], d);       
                }
            }
        }
        */
        
        
        int ans = 0;
        
        
        for(int len = 1;len<=min(m,n);len++) {
            //The loop to count how many square that width=len in matrix.
            for(int r=0;r<m-len+1;r++){
                for(int c=0;c<n-len+1;c++) {
                    //(r,c) is left-top corner of square
                    if(check(M,r,c,len)) ans++;
                    //if(M[r][c]==1) ans+=cnt[r][c];
                }
            }
        }
        
        /*
        for(int r =0;r<m;r++) {
            for(int c =0;c<n;c++) {
                //printf("%2d,",cnt[r][c]);
                ans+=cnt[r][c];
            }
            //printf("\n");
        }*/
        return ans;
    }
    int check(vector<vector<int>>& M, int r, int c, int len) {
        for(int row = r;row<r+len;row++) {
            for(int col =c; col<c+len;col++) {
                if(M[row][col] == 0) {
                    //printf("M[rc=(%d,%d)] = 0\n",row,col);
                    return 0;
                }
            }
        }
        return 1;
    }
    
};
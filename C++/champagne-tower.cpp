class Solution {
    //https://leetcode.com/problems/champagne-tower/
    //FB discussion https://www.facebook.com/groups/1451299754892511/posts/5123228467699603/
public:
        //Observation 
        //[0,0] pour [1,0]&[1,1]
        //[1,0] pour [2,0]&[2,1]
        //[1,1] pour [2,1]&[2,2]
        //[2,0] pour [3,0]&[3,1]
        //[2,1] pour [3,1]&[3,2]
        //[2,2] pour [3,2]&[3,3]
        //[i,j] pour [i+1,j] & [i+1,j+1]
        //So [i,j] is poured by dp[i-1,j] + dp[i-1,j-1] 
        
        
        // pour =4
        //    1
        //    1     1
        //   1/4   1/2   1/4
        
        // pour =5
        //    1
        //    1     1
        //   2/4    1    2/4

        // pour =6
        //    1
        //    1     1
        //   3/4    1    3/4
        //    0    1/4   1/4     0
        
        // pour =7
        //    1
        //    1     1
        //    1     1     1
        //    0    2/4   2/4     0
        
        // pour =8
        //    1
        //    1     1
        //    1     1     1
        //   1/8   7/8   7/8   1/8

        // pour =9
        //0    1
        //1    1     1
        //2    1     1     1
        //3   2/8    1     1     2/8
        //4    0    2/16  4/16   2/16   0        

        // pour =10 
        //0    1
        //1    1     1
        //2    1     1      1
        //3   3/8    1      1     3/8
        //4    0    5/16   10/16   5/16   0        

        // pour =11 
        //0    1
        //1    1     1
        //2    1     1      1
        //3   4/8    1      1     4/8
        //4    0    8/16    1    8/16   0        
    
        // pour =12 
        //0    1
        //1    1      1
        //2    1      1      1
        //3   5/8     1      1       5/8
        //4    0    11/16    1      11/16      0        
        //5    0      0     6/32     6/32      0      0

    
        // pour =13 
        //0    1
        //1    1      1
        //2    1      1      1
        //3   6/8     1      1       6/8
        //4    0    14/16    1      14/16      0        
        //5    0      0    12/32    12/32      0      0

        // pour =14 
        //0    1
        //1    1      1
        //2    1      1      1
        //3   6/8     1      1       6/8
        //4    0    14/16    1      14/16      0        
        //5    0      0    12/32    12/32      0      0
    
    
        // Speed
        //0   1/1
        //1   1/2        1/2
        //2   1/4        2/4      1/4
        //3   1/8        3/8      3/8       1/8     
        //4   1/16      4/16      6/16      4/16      1/16     
        //5   1/32      5/32      10/32     10/32     5/32     1/32     
        //6   1/64      6/64      15/64     20/64    15/64     6/64     1/64    
        
        //speed(i,j) = speed(i-1,j-1) + speed(i-1,j) for i>=0 && j>=0 
        //speed(i,j) = 0, otherwise
    
        
        /*
        
                    1
                 /     \ 
              1            1
            1   1        1   1
          1   2   1    1   2   1
               \         /
                 \     /
                   \ /
                    1
                 1     1
              1    1+1    1
           1    2+1   1+2    1
        
           example,
           s(p,3,1) = s(p-1,2,1) + s(p-1,2,0)
           
           So, 
           s(p,i,j) = s(p-1,i-1,j)/2 + s(p-1,i-1,j-1)/2;
           
           

        */
        /* By the way, this is Pascal's Triangle
                1
                1 1
                1 2 1
                1 3 3 1
                1 4 6 4 1
                1 5 10 10 5 1
                1 6 15 20 15 6 1
                .......................................

                �Ϥ@(a+b)0=1
                (a+b)1=1a+1b
                (a+b)2=1a2+2ab+1b2
                (a+b)3=1a3+3a2b+3ab2+1b3
                (a+b)4=1a4+4a3b+6a2b2+4ab3+1b4
                .............................................
                �@
                �ϤG 
        */
        
    /*
        1
        1 1
    */
    /*
    double speed(int i,int j, vector<vector<double>>& dp) {
        if(i<0||j<0) return 0;
        if(dp[i][j]>=0) return dp[i][j];
        dp[i][j] = speed(i-1,j-1,dp) + speed(i-1,j,dp);
        return dp[i][j];
    }*/
    
    double champagneTower(int poured, int query_row, int query_glass) {
        //s(p, i, j)=(s(p-1, i-1,j)-1)/2+(s(p-1, i-1,j-1)-1)/2
        
        //return (champagneTower(poured-1, query_row-1, query_glass)-1)/2 + (champagneTower(poured-1, query_row-1, query_glass-1)-1)/2;
            
        //vector<vector<double>> speed_dp = vector<vector<double>>(query_row+1, vector<double>(query_glass+1, -1));
        //speed_dp[0][0] = 1;
        //return testTower(poured, query_row,query_glass);
        //return 0;
        
        
        return s(poured, query_row, query_glass);
        
        double glass[101][101] = {0};
        glass[0][0] = poured; //start with the root
        for(int i = 0; i<100; i++){
            for(int j = 0; j<=i; j++){
                if(glass[i][j] >= 1){
                    glass[i + 1][j] += (glass[i][j] - 1) / 2; // left child
                    glass[i + 1][j + 1] += (glass[i][j] - 1) / 2; // right child
                    glass[i][j] = 1; // me
                }
            }
        }
        return glass[query_row][query_glass];
        //return s(poured, query_row, query_glass);
    }
    
    double s(double p, int i, int j) {
        if(i<0) return 0;
        if(j<0) return 0;
        if(i==0) return p;
        if(p<=0) return 0;
        if(p<1) return p;
        //return s( (p-1)/2, i-1,j ) +  s( (p-1)/2, i-1,j-1);
        return s( (p-1)/2, i-1,j ) +  s( (p-1)/2, i-1,j-1);
    }
    
    
    long speed(int i, int j, vector<vector<long long>> &dp) { 
        return 1;
    }
    
    double testTower(int poured, int query_row, int query_glass) {
        // pour =4
        //    1
        //    1     1
        //   1/4   1/2   1/4
        
        vector<double> dp(101, 0); dp[0] = poured;
        for(int row=1; row<=query_row; row++){
            for(int i=row; i>=0; i--) {
                //dp[i+1] += dp[i] = max(0.0, (dp[i]-1)/2);                
                dp[i] = max(0.0, (dp[i]-1)/2);                
                dp[i+1] += dp[i];
            }
        }

        return min(dp[query_glass], 1.0);
    }

};
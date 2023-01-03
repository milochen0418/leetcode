class Solution {
    //https://leetcode.com/problems/where-will-the-ball-fall
    //article https://leetcode.com/problems/where-will-the-ball-fall/discuss/2988343/C%2B%2B-O(N*M)-simulation
public:
    #define printf(...) empty_printf(__VA_ARGS__)
    #define empty_printf(...)
    
    vector<int> findBall(vector<vector<int>>& grid) {
        //pos(row,col), up ball/down ball   
        //cell_status: "\"  "/"
        //up ball in "\": if row,col+1 == "/" ->Ball Stop
        //up ball in "\": if row,col+1 == "\" ->Go ball down & go pos(row,col+1)
        //down ball in "\":  -> Go ball up & go pos(row+1,col)
        
        //up ball in "/": if row,col+１ == "\" ->Ball Stop
        //up ball in "/": if row,col+1 == "/" ->Go ball down & go pos(row,col-1)
        //down ball in "\":  -> Go ball up & go pos(row+1,col)
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> v = vector<vector<int>>(n,vector<int>());
        vector<int> ans = vector<int>(n,0);
        for(int i = 0; i<n;i++) {
            v[i] = {0,i,1};//1 is ball up, 0 is ball down
            ans[i] = i;
        }
        
        
        for(int i = 0; i<n;i++) {
            vector<int>& o = v[i];
            while(true) {
                if(grid[o[0]][o[1]] == 1) {
                    if(o[2]==1) {
                        if(o[1]+1>=n) {
                            ans[i] = -1;
                            break;
                        }else if(grid[o[0]][o[1]+1]==-1){
                            ans[i] = -1;
                            break;
                        }else{
                            o[1]=o[1]+1;
                            o[2]=-1;//ball go down
                        } 
                        printf("i=%d, (r,c)=(%d,%d,%d) up1/down-1\n",i,o[0],o[1],o[2]);
                    } else {//o[2]==0
                        o[2]=1;
                        o[0]=o[0]+1;
                        if(o[0]>=m) {
                            ans[i] = o[1];
                            break;
                        }
                        printf("i=%d, (r,c)=(%d,%d,%d) up1/down-1\n",i,o[0],o[1],o[2]);
                    }
                } else {
                    //grid[o[0]][o[1]] == -1
                    if(o[2]==1) {
                        if(o[1]-1<0) {
                            ans[i] = -1;
                            break;
                        }else if(grid[o[0]][o[1]-1]==1){
                            ans[i] = -1;
                            break;
                        }else{
                            o[1]=o[1]-1;
                            o[2]=-1;//ball go down
                        }  
                        printf("i=%d, (r,c)=(%d,%d,%d) up1/down-1\n",i,o[0],o[1],o[2]);
                    } else {
                        o[2]=1;
                        o[0]=o[0]+1;
                        if(o[0]>=m) {
                            ans[i] = o[1];
                            break;
                        } 
                        printf("i=%d, (r,c)=(%d,%d,%d) up1/down-1\n",i,o[0],o[1],o[2]);
                    }
                }
            }
        }
        return ans;
        
        
        
    }
};
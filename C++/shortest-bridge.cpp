class Solution {
    //https://leetcode.com/problems/shortest-bridge
    //article https://leetcode.com/problems/shortest-bridge/discuss/2249937/C%2B%2B-or-BFS%2BDFS-or-easy-understand-with-comment-and-printing-message
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5475743202448126/
public:
    int color;
    vector<int> sums = vector<int>(4,0);
    vector<vector<int>> rcs = vector<vector<int>>(4,vector<int>());
    vector<vector<int>> g;
    int m,n;
    const vector<vector<int>> dirs = {{0,-1}, {0,1}, {1,0}, {-1,0}};
    struct rc{int r; int c;};
    queue<rc> currQ;
    queue<rc> nextQ;
    int min_color;
    int max_color;
    void displayG(){
        int m = g.size(), n = g[0].size();
        printf("g = \n");
        for(int i = 0; i<m;i++) {
            for(int j =0; j<n;j++) {
                printf("%2d, ", g[i][j]);
            }
            printf("\n");
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        
        g = grid;
        m = g.size();
        n = g[0].size();
        printf("the original gird status when start.\n");
        displayG();
        //Step 1. Give color for the two component
        color = 2;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
               if(g[i][j] == 1) {
                   rcs[color] = {i,j};
                   sums[color++] = dfs(i, j);
               }
            }
        }
        printf("the gird status after step 1.\n");
        displayG();
        //Step 2. Decide who is min_color and max_color
        //min_color is the color for the component smaller than another one.
        //max_color is the color for the component larger than another one.
        min_color = (sums[2]<sums[3])?2:3;
        max_color = (sums[2]<sums[3])?3:2;
        printf("the min_color, max_color status after Step 2.\n");
        printf("min_color = %d\n",min_color);
        printf("max_color = %d\n",max_color);
        
        
        //Step 3. Use dfsQ for min_color to make first Q of BFS algorithm.
        //We expect change min_color into 1 after finish of this dfsQ().
        dfsQ(rcs[min_color][0], rcs[min_color][1]);
        min_color = 1;
        printf("Show the min_color and grid status after Step 3.\n");
        displayG();
        printf("min_color = %d\n", min_color);
        
            
        //Step 4. find the shortest path from all min_color node to 
        //the first max_color node by BFS.
        
        //printf("max_color = %d\n",max_color);
        int len = 0;
        while(!currQ.empty()) {
            rc e = currQ.front();
            currQ.pop();
            for(auto &d: dirs) {
                int r = e.r + d[0], c = e.c + d[1];
                if(r<0||r>=m||c<0||c>=n) continue;
                if(g[r][c] == 0 ) {
                    nextQ.push(rc{r,c});
                    g[r][c] = 1;//traveled
                } else if(g[r][c] == max_color) {
                    printf("Step 4. finished.\n");
                    printf("find out first node with max_color at g[%d][%d]\n",r,c);
                    printf("So, the length of shortest bridge = %d\n", len);
                    return len;
                }                
            }
            if(currQ.empty()) {
                swap(currQ, nextQ);
                len++;
            }
        }
        return 0;
        //find the shortest path from 2 to 3
        
    }
    void dfsQ(int i, int j){
        //Use DFS to push data in currQ
        g[i][j] = 1;//change to 1
        currQ.push(rc{i,j});
        for(auto &d: dirs) {
            int r = i+d[0], c = j+d[1];
            if(r<0||r>=m||c<0||c>=n) continue;
            if(g[r][c] == min_color) dfsQ(r,c);
        }
        
    }
    int dfs(int i, int j) {
        int sum = 1;
        g[i][j] = color;
        for(auto &d: dirs) {
            int r = i+d[0], c = j+d[1];
            if(r<0||r>=m||c<0||c>=n) continue;
            if(g[r][c] == 1) {
                sum+=dfs(r,c);
            }
        }
        return sum;
    }
};

/* test-case
Success: 
[[0,1],[1,0]]
[[0,1,0],[0,0,0],[0,0,1]]
[[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
[[0,1,0,0,0],[0,1,0,1,1],[0,0,0,0,1],[0,0,0,0,0],[0,0,0,0,0]]
Failed: 
*/
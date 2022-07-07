class Solution {
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
        color = 2;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
               if(g[i][j] == 1) {
                   rcs[color] = {i,j};
                   sums[color++] = dfs(i, j);
               }
            }
        }
        
        min_color = (sums[2]<sums[3])?2:3;
        max_color = (sums[2]<sums[3])?3:2;
        printf("min_color = %d\n",min_color);
        printf("max_color = %d\n",max_color);
        displayG();
            
        dfsQ(rcs[min_color][0], rcs[min_color][1]);
        displayG();
        min_color = 1;
        
        printf("max_color = %d\n",max_color);
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
                    printf("find out max_color at g[%d][%d]\n",r,c);
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
            if(g[r][c] == min_color) dfs(r,c);
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
Failed:
[[0,1,0,0,0],[0,1,0,1,1],[0,0,0,0,1],[0,0,0,0,0],[0,0,0,0,0]] 
*/
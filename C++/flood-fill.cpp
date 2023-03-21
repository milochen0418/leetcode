class Solution {
    //https://leetcode.com/problems/flood-fill
    //article https://leetcode.com/problems/flood-fill/discuss/2223544/C%2B%2B-or-BFS-is-better-than-DFS-or-time-O(n*m)-space-O(n%2Bm)
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5459766424045804/
public:
    vector<vector<int>>& floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        if(image[sr][sc] == color) return image;
        int origin = image[sr][sc];    
        vector<vector<int>> dirs={{0,-1},{0,1},{1,0},{-1,0}};
        function<void(int,int)> dfs = [&](int r, int c) {
            image[r][c] = color;
            for(auto &d: dirs) {
                int row = r+d[0];
                int col = c+d[1]; //row,col neighberhood of r,c
                if(row<0 || col<0 || row>=m || col>=n) continue;
                if(image[row][col] == origin) dfs(row,col);
            }
        };
        
        function<void(int,int)> bfs = [&](int r, int c) {
            queue<vector<int>> Q;
            Q.push({r,c});
            while(!Q.empty()) {
                vector<int> e = Q.front();
                Q.pop();
                int r = e[0], c=e[1];
                image[r][c] = color;
                for(auto &d: dirs) {
                    int row = r+d[0];
                    int col = c+d[1]; //row,col neighberhood of r,c
                    if(row<0 || col<0 || row>=m || col>=n) continue;
                    if(image[row][col] == origin) Q.push({row,col});
                }
            }
        };
        dfs(sr,sc);
        //bfs(sr,sc);
        return image;
    }
};
class Solution {
    //https://leetcode.com/problems/flood-fill
    //article https://leetcode.com/problems/flood-fill/discuss/2223544/C%2B%2B-or-BFS-is-better-than-DFS-or-time-O(n*m)-space-O(n%2Bm)
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5459766424045804/
public:
    //DFS Solution
    int orig_color, new_color, m, n;
    vector<vector<int>>* img;
    const vector<vector<int>> dirs ={{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<int>>& floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n =image[0].size();
        orig_color = image[sr][sc];
        new_color = color;
        if(color==orig_color) return image;
        img = &image;
        dfs(sr,sc);
        return image;
    }
    void dfs(int i, int j) {
        vector<vector<int>>& a = *img;
        a[i][j] = new_color;
        for(auto &d: dirs){
            int r = i+d[0], c = j+d[1];
            if(r<0||r>=m||c<0||c>=n) continue;
            if(a[r][c] == orig_color) dfs(r,c);
        }
    }
    //BFS Solution
    struct rc{int r;int c;};
    vector<vector<int>> floodFillBFS(vector<vector<int>>& image, int sr, int sc, int color) {
        int orig_color = image[sr][sc];
        if(color == orig_color) return image;
        int m = image.size(), n= image[0].size();
        
        vector<rc> dirs= { 
                rc{-1,0},
            rc{0,-1},   rc{0,+1},
                rc{+1,0}
        };
        queue<rc> Q; 
        image[sr][sc] = color;
        Q.push(rc{sr,sc});
        while(!Q.empty()) {
            rc e = Q.front();
            Q.pop();
            for(auto &d: dirs) {
                int r = e.r+d.r;
                int c = e.c+d.c;
                if(r<0 || r>=m || c<0 || c>=n) continue;
                if(image[r][c] == orig_color) {
                    image[r][c] = color;
                    Q.push(rc{r,c});    
                }
            }
        }
        return image;
    }
};
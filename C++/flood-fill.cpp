class Solution {
    //https://leetcode.com/problems/flood-fill
public:
    struct rc{
        int r;
        int c;
    };
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
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
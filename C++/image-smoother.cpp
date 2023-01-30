class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n=img[0].size();
        vector<vector<int>> next_img = vector<vector<int>>(m,vector<int>(n,0));
        
        vector<vector<int>> dirs=vector<vector<int>>(9,vector<int>(2,0));
        //Set dirs = (-1,-1),(-1,0),(-1,1),(0,-1),(0,0),(0,1),(1,-1),(1,0),(1,1),
        for(int i = 0;i<9;i++) 
            dirs[i] = {(i/3)-1, (i%3)-1};
        
        for(int i = 0; i<m; i++) {
            for(int j=0; j<n;j++) {
                int cnt=0, sum=0;
                for(auto &d:dirs) {
                    int r = i+d[0], c=j+d[1];
                    if(r<0||r>=m||c<0||c>=n)continue;
                    cnt++;
                    sum+=img[r][c];
                }
                next_img[i][j]=sum/cnt;
            }
        }
        return next_img;
        
    }
};
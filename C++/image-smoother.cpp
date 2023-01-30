class Solution {
public:
    vector<vector<int>>& imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n=img[0].size();
        vector<vector<int>> &ans = img;
        vector<vector<int>> dirs= vector<vector<int>>(9,vector<int>(2,0));
        for(int i = 0;i<9;i++) dirs[i] = {(i/3)-1, (i%3)-1};
        for(int i = 0; i<m; i++) {
            for(int j=0; j<n;j++) {
                int cnt=0, sum=0;
                for(auto &d:dirs) {
                    int r = i+d[0], c=j+d[1];
                    if(r<0||r>=m||c<0||c>=n)continue;
                    cnt++;
                    sum+=(img[r][c]&0x00ff);
                }
                ans[i][j]|=(sum/cnt)<<8;
            }
        }
        for(int i = 0; i<m; i++)
            for(int j=0; j<n;j++)
                ans[i][j]>>=8;
        return ans;
    }

    vector<vector<int>> imageSmoother_v01(vector<vector<int>>& img) {
        int m = img.size(), n=img[0].size();
        vector<vector<int>> ans = vector<vector<int>>(m,vector<int>(n,0));
        vector<vector<int>> dirs= vector<vector<int>>(9,vector<int>(2,0));
        for(int i = 0;i<9;i++) dirs[i] = {(i/3)-1, (i%3)-1};
        for(int i = 0; i<m; i++) {
            for(int j=0; j<n;j++) {
                int cnt=0, sum=0;
                for(auto &d:dirs) {
                    int r = i+d[0], c=j+d[1];
                    if(r<0||r>=m||c<0||c>=n)continue;
                    cnt++;
                    sum+=img[r][c];
                }
                ans[i][j]=sum/cnt;
            }
        }
        return ans;
    }
};
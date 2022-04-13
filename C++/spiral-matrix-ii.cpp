class Solution {
    //https://leetcode.com/problems/spiral-matrix-ii
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans = vector<vector<int>>(n, vector<int>(n,0));
        //n=1, 1
        //n=2, 4
        //n=3, 8 - 1
        //n=4, 12 - 4 - 0
        //n=5, 16 - 8 - 1
        //n=6, 20 - 12 - 4 
        //n=7, 24 - 16 - 8 - 1 
        //n=8, 28 - 20 - 12 - 4
        
        draw(n,0,1,ans);
        return ans;        
    }
    void draw(int n, int k, int cnt, vector<vector<int>>& ans) {
        if(n-k<=0) return;
        if(n-k==1) ans[(n-1)-k/2][(n-1)-k/2] = cnt++;
        if(n-k>=2) {
            int L = k/2, H=n-1-(k/2); //L mean low, H mean high
            for(int col = L; col<H;col++) ans[L][col] = cnt++;
            for(int row = L; row<H;row++) ans[row][H] = cnt++;
            for(int col = H; col>L;col--) ans[H][col] = cnt++;
            for(int row = H; row>L;row--) ans[row][L] = cnt++;
        }
        draw(n, k+2, cnt, ans);
    }
};
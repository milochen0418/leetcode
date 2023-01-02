class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        const int X=1000;
        vector<vector<int>> ds = {{0,1},{1,0},{0,-1},{-1,0}};
        int didx = 0;
        vector<int>ans;
        vector<int> pos={0,0};
        while(true) {
            int& v = matrix[pos[0]][pos[1]];
            ans.push_back(v);
            v=X;
            int row = pos[0]+ds[didx][0];
            int col = pos[1]+ds[didx][1];
            if(row<0 || row>=m || col<0||col>=n|| matrix[row][col]==X ) {
                didx=(didx+1)%ds.size();
                row = pos[0]+ds[didx][0];
                col = pos[1]+ds[didx][1];
                if(row<0 || row>=m || col<0||col>=n|| matrix[row][col]==X ) {
                    break;
                } 
            }
            pos={row,col};            
        }
        return ans;
    }
};
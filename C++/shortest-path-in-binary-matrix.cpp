class Solution {
    //https://leetcode.com/problems/shortest-path-in-binary-matrix
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n = grid.size(), len = 1;        
        vector<vector<int>> dir = {
            {-1,-1},{-1,+0},{-1,+1},
            {+0,-1},        {+0,+1},
            {+1,-1},{+1,+0},{+1,+1}
        };
        queue<int> currQ, nextQ;
        currQ.push( get_id({0,0},n) );
        grid[0][0] = 1;        
        while(!currQ.empty()) {
            vector<int> rc = get_rc(currQ.front(),n);
            if(rc[0]==n-1 && rc[1]==n-1) return len;
            currQ.pop();
            for(auto& d : dir) {
                int row = rc[0]+d[0], col = rc[1]+d[1];
                if( row<0 || col<0 || row>=n || col>=n) continue;
                if(grid[row][col]==0) {
                    nextQ.push(get_id({row,col},n));
                    grid[row][col] = 1;
                } 
            }
            if(currQ.empty()) {
                swap(currQ, nextQ);
                len++;
            }
        }
        return -1;
    }
    int get_id(vector<int> row_col, int size_n) {
        int row = row_col[0];
        int col = row_col[1];
        return row*size_n + col;
    }
    vector<int> get_rc(int id, int size_n) {
        vector<int> row_col = vector<int>(2,0);
        row_col[0] = id / size_n;
        row_col[1] = id % size_n;
        return row_col;
    }
};
class Solution {
    //https://leetcode.com/problems/shortest-path-in-binary-matrix
    //article https://leetcode.com/problems/shortest-path-in-binary-matrix/discuss/2045236/C%2B%2B-or-BFS-or-Explanation
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5324759520879829/
public:
    struct _rc{ int row; int col; };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<_rc> currQ, nextQ;
        if(grid[0][0]++>0) return -1;
        currQ.push(_rc{0,0});
        int n = grid.size(), len = 1;        
        vector<_rc> dir = {        
            _rc{-1,-1},_rc{-1,+0},_rc{-1,+1},
            _rc{+0,-1},           _rc{+0,+1},
            _rc{+1,-1},_rc{+1,+0},_rc{+1,+1}
        };
        while(!currQ.empty()) {
            _rc rc = currQ.front();
            if(rc.row==n-1 && rc.col==n-1) return len;
            currQ.pop();
            for(auto& d : dir) {
                int row = rc.row+d.row, col = rc.col+d.col;
                if( row<0 || col<0 || row>=n || col>=n) continue;
                if(grid[row][col]++==0) nextQ.push(_rc{row,col});
            }
            if(currQ.empty()) {
                swap(currQ, nextQ);
                len++;
            }
        }
        return -1;
    }
};
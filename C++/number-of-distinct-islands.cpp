class Solution {
    //https://leetcode.com/problems/number-of-distinct-islands
    //article https://leetcode.com/problems/number-of-distinct-islands/discuss/2049792/C%2B%2B-or-BFS-or-easy-understand-and-explanation
    //FB post https://www.facebook.com/groups/1451299754892511/posts/5328977077124740/
public:
    struct _rc {int row; int col;};
    struct vector_hasher {
        int operator()(const vector<int> &V) const {
            long hash = V.size();
            for(auto &i : V) {
                hash ^= (i + 0x9e3779b9 + (hash << 6) + (hash >> 2)) % INT_MAX;
            }
            return hash;
        }
    };    
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<vector<int>, vector_hasher> s;
        int m = grid.size(), n = grid[0].size();
        vector<_rc> dir = {_rc{-1,0},_rc{1,0},_rc{0,-1},_rc{0,1}};
        for(int i = 0; i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 0) continue;
                grid[i][j]--;
                queue<_rc> q;
                q.push(_rc{i,j});
                vector<int> dv; 
                while(!q.empty()) {
                    _rc rc = q.front();
                    q.pop();
                    for(int k = 0; k < dir.size();k++) {
                        _rc d = dir[k];
                        int row = rc.row + d.row;
                        int col = rc.col + d.col;
                        if(row<0||row>=m||col<0||col>=n) {
                            dv.push_back(-1);
                            continue;
                        }
                        if(grid[row][col]==1) {
                            grid[row][col]--;
                            q.push(_rc{row,col});
                            dv.push_back(k);
                        } else {
                            dv.push_back(-1);
                        }
                    }
                }
                s.insert(dv);
            }
        }
        return s.size();
    }
};
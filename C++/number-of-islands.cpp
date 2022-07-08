class Solution {
    // https://leetcode.com/problems/number-of-islands
public:



    struct rc{int r;int c;};
    int numIslandsBFS(vector<vector<char>>& grid) {
        queue<rc> Q;
        int ans = 0;
        int m = grid.size(), n=grid[0].size();
        const vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i = 0; i<m;i++){
            for(int j = 0; j<n;j++) {
                if(grid[i][j]=='1') {
                    ans++;
                    Q.push({i,j});
                    grid[i][j] = '0';
                    while(!Q.empty()) {
                        rc e = Q.front();
                        Q.pop();
                        for(auto &d: dirs){
                            int r = e.r+d[0], c = e.c+d[1];
                            if(r<0||r>=m||c<0||c>=n) continue;
                            if(grid[r][c]=='1') {
                                Q.push({r,c});
                                grid[r][c] = '0';
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }


    vector<vector<char>>* pGrid;
    const vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    int m,n;
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        pGrid = &grid;
        m=grid.size();
        n=grid[0].size();
        for(int i = 0; i<m;i++){
            for(int j = 0;j<n;j++) {
                if(grid[i][j]=='1') {
                    dfs(i,j);
                    ans++;
                }   
            }        
        }
        return ans;
    }
    
    void dfs(int i, int j) {
        vector<vector<char>>& g = *pGrid;
        g[i][j] = '0';
        for(auto &d: dirs) {
            int r = i+d[0], c = j+d[1];
            if(r<0||r>=m||c<0||c>=n) continue;
            if(g[r][c] == '1') dfs(r,c);
        }
    }


    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;  
        }
    };
    
    typedef pair<int,int> _pos;
    typedef unordered_map< pair<int,int>, pair<int,int>, pair_hash> _parent_map;
    typedef vector<vector<char>> _grid; 
    
    int set_cnts = 0; 
    int numIslandsUF(vector<vector<char>>& grid) {
        _pos a = {1,2};
        _parent_map parents;
        int rows = grid.size();
        int cols = grid[0].size();        
        for(int row=0;row<rows; row++) {
            for(int col=0;col<cols; col++) {
                if(grid[row][col]=='1') {
                    parents[{row,col}] = {row,col};
                    set_cnts++;
                }
            }
        }
        
        for(int row=0;row<rows; row++) {
            for(int col=0;col<cols; col++) {
                if(grid[row][col]=='1') {
                    if(row+1 < rows && grid[row+1][col] == '1') {
                        UF_union(parents, {row,col}, {row+1,col});
                    }
                    if(col+1 < cols && grid[row][col+1] == '1') {
                        UF_union(parents, {row,col}, {row,col+1});
                    }
                    if(col-1 >=0 && grid[row][col-1] == '1') {
                        UF_union(parents, {row,col}, {row,col-1});
                    }                    
                    if(row-1 >= 0 && grid[row-1][col] == '1') {
                        UF_union(parents, {row,col}, {row-1,col});
                    }
                }
            }
        }
        return set_cnts;
    }
    
    _pos UF_find_root(_parent_map& ps,  _pos node ) {
        _pos root = node;
        while(ps[root] != root) {
            root = ps[root];    
        }
        return root;
    }
    
    bool UF_is_connected(_parent_map& ps, _pos node1, _pos node2) {
        return UF_find_root(ps, node1) == UF_find_root(ps, node2);
    }
    
    void UF_union(_parent_map& ps, _pos node1, _pos node2) {
        _pos root1 = UF_find_root(ps, node1);
        _pos root2 = UF_find_root(ps, node2);
        if(root1 == root2) return;
        ps[root2] = root1;
        set_cnts--;
    }  
};



/* test-case
[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
[["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]
*/
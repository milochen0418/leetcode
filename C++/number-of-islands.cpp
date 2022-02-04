class Solution {
    // https://leetcode.com/problems/number-of-islands
public:
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            // Mainly for demonstration purposes, i.e. works but is overly simple
            // In the real world, use sth. like boost.hash_combine
            return h1 ^ h2;  
        }
    };
    
    typedef pair<int,int> _pos;
    typedef unordered_map< pair<int,int>, pair<int,int>, pair_hash> _parent_map;
    typedef vector<vector<char>> _grid; 
    
    int numIslands(vector<vector<char>>& grid) {
        _parent_map parents;
        int rows = grid.size();
        int cols = grid[0].size();        
        for(int row=0;row<rows; row++) {
            for(int col=0;col<cols; col++) {
                if(grid[row][col]=='1') {
                    parents[{row,col}] = {row,col};
                }
            }
        }
        return 0;
    }
    _pos findRoot(_parent_map& ps, _grid& g,  _pos& node ) {
        
        return {1,2};
    }
};
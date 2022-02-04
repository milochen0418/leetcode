class Solution {
    // https://leetcode.com/problems/number-of-islands-ii
public:
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
    
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int rows = m, cols = n;
        _grid grid(rows, vector<char>(cols,'0'));
        _parent_map ps;
        vector<int> result;
        for(auto& pos :positions) {
            int row = pos[0];
            int col = pos[1];
            grid[row][col]='1';
            ps[{row, col}] = {row, col};
            set_cnts+=1;
            if(row+1 < rows && grid[row+1][col] == '1') {
                UF_union(ps, {row,col}, {row+1,col});
            }
            if(col+1 < cols && grid[row][col+1] == '1') {
                UF_union(ps, {row,col}, {row,col+1});
            }
            if(col-1 >=0 && grid[row][col-1] == '1') {
                UF_union(ps, {row,col}, {row,col-1});
            }                    
            if(row-1 >= 0 && grid[row-1][col] == '1') {
                UF_union(ps, {row,col}, {row-1,col});
            }
            result.push_back(set_cnts);
        }
        return result;
        
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
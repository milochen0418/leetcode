class Solution {
    //https://leetcode.com/problems/graph-valid-tree
public:
    int set_cnt=0;
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> ps(n); //parents
        for(int i=0;i<n;i++) {
            ps[i] = i;
            set_cnt++;
        }
        
        for( auto& edge: edges) {
            if( UF_is_connected(ps, edge[0], edge[1])) return false;
            UF_union(ps, edge[0], edge[1]);
        }
        if(set_cnt!=1) return false; 
        //Because two component is not tree by test-case
        
        return true;
    }
    
    int UF_find_root(vector<int>&ps, int n) {
        int root = n;
        while(ps[root] != root) root = ps[root];
        return root;
    }
    
    bool UF_is_connected(vector<int>&ps, int a, int b) {
        return UF_find_root(ps, a) == UF_find_root(ps, b);
    }
    
    void UF_union(vector<int>&ps, int a, int b) {
        int root_a = UF_find_root(ps, a);
        int root_b = UF_find_root(ps, b);
        if(root_a == root_b) return;
        ps[root_b] = root_a;
        set_cnt--;
    }
};
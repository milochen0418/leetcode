class Solution {
    //https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/
public:
    int set_cnt=0;
    int earliestAcq(vector<vector<int>>& logs, int n) {
        vector<int> ps(n);
        for(int i=0;i<n;i++) ps[i]=i;
        set_cnt = n;
        
        for(auto& v:logs) {
            int t=v[0], x=v[1], y=v[2];
            UF_union(ps, x, y);
            if(set_cnt ==1) return t;
        }
        return -1;
    }
    
    int UF_find_root(vector<int>& ps, int node) {
        int root = node;
        while(ps[root] != root)root = ps[root];
        return root;
    }
    
    bool UF_is_connected(vector<int>& ps, int a, int b) {
        return UF_find_root(ps, a) == UF_find_root(ps, b);
    }
    
    void UF_union(vector<int>&ps, int a, int b) {
        int root_a = UF_find_root(ps, a);
        int root_b = UF_find_root(ps, b);
        if(root_a == root_b) return; 
        ps[root_a] = root_b;
        set_cnt-=1;
    }  
};


/* testcase
[[0,2,0],[1,0,1],[3,0,3],[4,1,2],[7,3,1]]
4
[[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]]
6
[[9,3,0],[0,2,1],[8,0,1],[1,3,2],[2,2,0],[3,3,1]]
4
*/
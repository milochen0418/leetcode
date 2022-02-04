class Solution {
    //https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/
    //article https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5038828492806268/
public:
    int set_cnt=0;
    int earliestAcq(vector<vector<int>>& logs, int n) {
        vector<int> ps(n);
        for(int i=0;i<n;i++) ps[i]=i;
        set_cnt = n;
        sort(logs.begin(), logs.end(), [](auto r, auto l){return r[0]<l[0];});
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
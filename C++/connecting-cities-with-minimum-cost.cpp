class Solution {
    //https://leetcode.com/problems/connecting-cities-with-minimum-cost/
public:
    //typedef unordered_map< pair<int,int>, pair<int,int>, pair_hash> _parent_map;
    //typedef unordered_map< pair<int,int>, int, pair_hash> _size_map;
    vector<int> p;
    vector<int> sz; 
    int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), [](auto& lhs, auto& rhs){
            return lhs[2] < rhs[2];
        });
        
        for(auto&e :connections) {
            printf("(%d,%d,%d)\n", e[0], e[1], e[2]);
        }
        cout<<"\n";
        
        p = vector<int>(n+1,0);
        sz = vector<int>(n+1,0);
        for(int i = 1;i<=n;i++) {
            sz[i] = 1;
            p[i] = i;
        }
        
        int cnt=0;
        int sum_cost=0;
        //for(auto&e :connections) {
        for(int i = 0;i<connections.size();i++) {
            vector<int> &e = connections[i];
            if(!UF_is_connected( p, e[0], e[1] )) { //not in same component
                UF_union(p,sz, e[0],e[1]);
                sum_cost += e[2];
                cnt+=1;
            }
            if(cnt >= n-1) break;
        }
        if(cnt<n-1) return -1;
        return sum_cost;
        //return 0;
    }
    
    int UF_find_root(vector<int>& p,int node) {
        while(p[node] != node) node = p[node];
        return node; 
    }
    bool UF_is_connected(vector<int>& p, int node1, int node2){
        int root1 = UF_find_root(p, node1);
        int root2 = UF_find_root(p, node2);
        return root1 == root2;
    }
    
    void UF_union(vector<int>& p, vector<int>& sz, int node1 , int node2) {
        int root1 = UF_find_root(p, node1);
        int root2 = UF_find_root(p, node1);
        if(root1==root2) return;
        if(sz[root1] <sz[root2]) {
            p[root1] = root2;
            sz[root2] += sz[root1];
        } else {
            p[root2] = root1;
            sz[root1] += sz[root2];
        }
        /*
        if(root1 == root2) return;
        p[root2] = root1;
        */

    }
};
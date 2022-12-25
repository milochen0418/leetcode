class Solution {
    //https://leetcode.com/problems/sum-of-distances-in-tree
    //article https://leetcode.com/problems/sum-of-distances-in-tree/discuss/2950873/C%2B%2B-or-two-DFS-or-explanation
public:
    unordered_map<int,vector<int>> mp;
    int n;
    vector<int> dfs1_visited;
    vector<int> num_nodes;
    vector<int> high; //high from root=0;
    
    vector<int> dfs2_visited;
    vector<int> sum_dist;
    int root_dist_sum = 0;
    
    vector<int> sumOfDistancesInTree(int _n, vector<vector<int>>& edges) {
        n = _n;
        for(auto &e:edges) {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        num_nodes = vector<int>(n,-1);
        sum_dist = vector<int>(n,-1);
        high = vector<int>(n,0); //high from root=0;
        dfs1_visited = vector<int>(n,0);
        dfs2_visited = vector<int>(n,0);
        dfs1(0,0); //figure out num_nodes[0..n)
        for(auto&i:high ) root_dist_sum+=i;    
        //printf("root_dist_sum = %d\n", root_dist_sum);
        sum_dist[0] = root_dist_sum;
        /*
        printf("high = ");
        for(auto &i:high) printf("%d,",i);
        printf("\n");
        
        printf("num_nodes = ");
        for(auto &i:num_nodes) printf("%d,",i);
        printf("\n");
        */
        dfs2(-1,0);
        /*
        printf("sum_dist = ");
        for(auto &i:sum_dist) printf("%d,",i);
        printf("\n");
        */
        return sum_dist;
        
    }
    void dfs2(int parent, int root) {
        //printf("p%d,r%d\n",parent, root);
        dfs2_visited[root] = 1;
        if(parent != -1) {
            sum_dist[root] = sum_dist[parent]+(n-num_nodes[root]) -num_nodes[root];
        }
        
        for(auto &i: mp[root]) {
            if(!dfs2_visited[i]) {
                dfs2(root, i);
            }
        }
        
    }
    
    int dfs1(int root,int h) {
        dfs1_visited[root] = 1;
        int sum = 1;
        for(auto &i: mp[root]) { 
            if(!dfs1_visited[i]) {
                sum+=dfs1(i,h+1);
            }
        }
        //printf("sum nodes for root %d is %d\n",root,sum);
        num_nodes[root] = sum;
        high[root] = h;        
        return num_nodes[root];
    }
};
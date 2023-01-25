class Solution {
    //https://leetcode.com/problems/find-closest-node-to-given-two-nodes
public:
    vector<int> dist1;
    vector<int> dist2;
    vector<int> sols;
    unordered_set<int> s1;
    unordered_set<int> s2;
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1 == node2) return node1; 
        
        int n = edges.size();
        dist1 = vector<int>(n,-1);
        dist2 = vector<int>(n,-1);
        sols = vector<int>(n,-1);
        
        
        path(edges, node1, s1, dist1);
        path(edges, node2, s2, dist2);
        
        
        /*
        printf("dist1 = ");
        for(int i = 0; i < n; i++) printf("%d, ", dist1[i]);
        printf("\n");
        
        printf("dist2 = ");
        for(int i = 0; i < n; i++) printf("%d, ", dist2[i]);
        printf("\n");
        */
        for(int i = 0; i < n;i++) {
            if(dist1[i] == -1 || dist2[i] == -1) {
                sols[i] = -1;
            } else {
                sols[i] = max(dist1[i], dist2[i]);
            }
        }
        /*
        printf("sols = ");
        for(int i = 0; i < n; i++) printf("%d, ", sols[i]);
        printf("\n");
        */
        int ans=-1; //index of solution
        int val = INT_MAX;
        for(int i = 0; i<n;i++) {
            if(sols[i] != -1) {
                if(sols[i]<val) {
                    val = sols[i];
                    ans = i;
                }                
            }
        }
        
        return ans;
    }
    void path(vector<int>& es, int root, unordered_set<int>&s, vector<int>& dist) {
        int len = 0;
        s.insert(root);
        dist[root] = len++;
        
        while(1) {
            root = es[root];
            if(root == -1) break;
            if(s.find(root) != s.end()) break;//cycle case happen
            s.insert(root);
            dist[root] = len++;
        }
    }
};
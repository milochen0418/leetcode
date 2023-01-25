class Solution {
    //https://leetcode.com/problems/find-closest-node-to-given-two-nodes
    //article https://leetcode.com/problems/find-closest-node-to-given-two-nodes/discuss/3096737/C%2B%2B-O(N)-HashSet-and-HashMap
public:
    #define printf(...) empty_printf(__VA_ARGS__)
    #define empty_printf(...)    
    #define print_container(name) printf("%s = ",#name);for(auto &i:name)printf("%d,",i);printf("\n");
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> path1={node1};//path start from node1;
        unordered_set<int> path1set={node1};
        vector<int> path2={node2};//path start from node2;
        unordered_set<int> path2set={node2};
        while(path1.back()!=-1) {
            int newv = edges[path1.back()];
            if(path1set.find(newv) != path1set.end()) break;//cycle detect
            path1set.insert(newv);
            path1.push_back(newv);
        }
        while(path2.back()!=-1) {
            int newv = edges[path2.back()];
            if(path2set.find(newv) != path2set.end()) break;//cycle detect
            path2set.insert(newv);
            path2.push_back(newv);
        }
        /*
        //if one have cycle but another doesn't have 
        if((path1.back() == -1 && path2.back() != -1)|| 
           (path1.back() != -1 && path2.back() == -1)
          ) return -1;  
        
        //if both are not cycle
        if(path1.back() == -1 && path2.back() == -1) {
            //find the final common point from backward
            //So it is same as  to find the first common vertex from forward
            reverse(path1.begin(),path1.end());
            reverse(path2.begin(),path2.end());
            int n = min(path1.size(), path2.size());
            int candidate=-1;
            for(int i = 0;i<n;i++) {
                if(path1[i]!=path2[i]) break;;
                candidate = path1[i];
            }
            return candidate;
        }
        
        */
        //case of the both are cycle
        unordered_set<int> intersection;// intersection set of path1set & path2set
        for(auto &i:path1set) if(path2set.find(i)!=path2set.end()) intersection.insert(i);
        if(intersection.empty()) return -1;//no common vertex
        /*
        printf("case of the both are cycle. and there is common vertext\n");
        printf("node1=%d, node2=%d\n",node1,node2);
        print_container(edges);
        print_container(intersection);
        print_container(path1);
        print_container(path2);*/
        unordered_map<int,int>dist1;
        unordered_map<int,int>dist2;
        for(int i = 0;i<path1.size();i++) dist1[path1[i]]=i;
        for(int i = 0;i<path2.size();i++) dist2[path2[i]]=i;
        
        
        int mindist = INT_MAX;
        int ans = INT_MAX;
        for(auto &i:intersection) {
            int dist = max(dist1[i],dist2[i]);
            //printf("case i = %d:, dist1[]=%d, dist2[]=%d -> dist = %d. mindist=%d\n",i,dist1[i],dist2[i],dist,mindist);
            if(dist<=mindist) {
                if(dist==mindist) {
                    if(i<ans)ans=i;//smallest index    
                } else {
                    ans=i;
                }
                mindist = dist;
            }
        }
        return ans;
    }


    vector<int> dist1;
    vector<int> dist2;
    vector<int> sols;
    unordered_set<int> s1;
    unordered_set<int> s2;
    
    int closestMeetingNode_v01(vector<int>& edges, int node1, int node2) {
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
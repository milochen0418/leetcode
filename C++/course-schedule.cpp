class Solution {
public:
    //https://leetcode.com/problems/course-schedule
    //Refer this article first to understand topological sort more
    //https://www.geeksforgeeks.org/detect-cycle-in-directed-graph-using-topological-sort/
    
     #define print_container(name) printf("%s = ",#name);for(auto &i:name)printf("%d,",i);printf("\n");
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        for(auto &e:prerequisites) {
            mp[e[1]].push_back(e[0]);
        }
        vector<int> v;
        vector<int> visited = vector<int>(numCourses,0);
        int detect_cycle=0;
        
        function<void(int)> dfs = [&](int parent) {
            visited[parent] = 1;
            for(auto &child:mp[parent]){
                if(visited[child] == 0) {
                    dfs(child);
                } else {
                    printf("detect_cycle for parent=%d, child=%d\n", parent, child);
                    detect_cycle=1;
                }
            }
            v.push_back(parent);
        };
        
        for(int i = 0;i<numCourses;i++) {
            if(!visited[i]) {
                detect_cycle=0;
                dfs(i);
                if(detect_cycle)return false;
            }
        }
        
        reverse(v.begin(), v.end());
        printf("v.size() = %d\n", (int)v.size());
        print_container(v);
        if(detect_cycle) return false;
        return true;
    }
    
    
};
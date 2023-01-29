class Solution {
public:
    //https://leetcode.com/problems/course-schedule
    //Refer this article first to understand topological sort more
    //https://www.geeksforgeeks.org/detect-cycle-in-directed-graph-using-topological-sort/
    //#define printf(...) empty_printf(__VA_ARGS__)
    #define empty_printf(...)
    #define print_container(name) printf("%s = ",#name);for(auto &i:name)printf("%d,",i);printf("\n");
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        for(auto &e:prerequisites) {
            //mp[e[1]].push_back(e[0]);
            mp[e[0]].push_back(e[1]);//reverse edge
        }

        for(int i = 0;i<numCourses;i++) {
            printf("i=%d ->",i);
            print_container(mp[i]);
        }

        
        
        vector<int> v;
        vector<int> color = vector<int>(numCourses,-1);//-1 is mean no color
        vector<int> pathover = vector<int>(numCourses,0);
        int detect_cycle=0;
        
        
        function<void(int,int)> dfs = [&](int parent,int root) {
            if(detect_cycle) return;
            pathover[parent] = 1;
            color[parent] = root;
            //v.push_back(parent);
            for(auto &child:mp[parent]){
                if(pathover[child]==1) {
                    printf(" || detect_cycle for parent=%d, child=%d\n", parent, child);
                    detect_cycle=1;                    
                } else {
                    printf("->%d",child);
                    if(color[child]==root || color[child]==-1){
                        dfs(child, root);
                    }
                }
                if(detect_cycle) break;
            }
            v.push_back(parent);
            pathover[parent] = 0;
        };
        
        for(int i = 0;i<numCourses;i++) {
            if(color[i]==-1) {
                printf("\nDFS init to start from %d", i);
                detect_cycle=0;
                dfs(i,i);
                if(detect_cycle)return false;
            }
        }
        
        
        //reverse(v.begin(), v.end());
        printf("v.size() = %d\n", (int)v.size());
        print_container(v);
        if(detect_cycle) return false;
        return true;
    }
    
    
};
/* Test Cases
2
[[1,0],[0,1]]
5
[[1,4],[2,4],[3,1],[3,2]]
*/
/* Test Cases
2
[[1,0],[0,1]]
5
[[1,4],[2,4],[3,1],[3,2]]
*/
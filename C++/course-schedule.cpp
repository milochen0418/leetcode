class Solution {
    //https://leetcode.com/problems/course-schedule
    //add article https://leetcode.com/problems/course-schedule/discuss/3114572/C%2B%2B-preorder-DFS-approach
    //Refer this article first to understand topological sort more
    //https://www.geeksforgeeks.org/detect-cycle-in-directed-graph-using-topological-sort/    
    //FB post https://www.facebook.com/groups/1451299754892511/posts/6087354007953706/
    
public:
    #define DEBUG
    #ifndef DEBUG
        #define printf(...) empty_printf(__VA_ARGS__)
    #endif 
    #define empty_printf(...)
    #define print_container(name) printf("%s = ",#name);for(auto &i:name)printf("%d,",i);printf("\n");
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Preorder-DFS approach
        unordered_map<int,vector<int>> mp;
        for(auto &e:prerequisites) {
            mp[e[0]].push_back(e[1]);//reverse edge
        }

        for(int i = 0;i<numCourses;i++) {
            printf("i=%d ->",i);
            print_container(mp[i]);
        }
        
        vector<int> color = vector<int>(numCourses,-1);//-1 is mean no color
        vector<int> pathover = vector<int>(numCourses,0);
        int detect_cycle=0;        
        function<void(int,int)> dfs = [&](int parent,int root) {
            if(detect_cycle) return;
            pathover[parent] = 1;
            color[parent] = root;//preorder-DFS here by putting the color of starting node, which is called root.
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
            pathover[parent] = 0;
        };
        
        for(int i = 0;i<numCourses;i++) {
            if(color[i]==-1) {
                printf("\nDFS init to start from %d", i);
                detect_cycle=0;
                dfs(i,i);
                if(detect_cycle)return false;
            } else {
                printf("\nDFS cannot init to start from %d, since its color=%d\n ", i,color[i]);
            }
        }
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
class Solution {
    //https://leetcode.com/problems/parallel-courses
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        unordered_set<int> left; // set of courses we haven't found the depth for yet
        vector<int> D(n+1, 0); // "depth"
        vector<vector<int>> IE(n+1); // In edges
        int m = relations.size();
        for(int i=0; i < m; ++i)
            IE[relations[i][1]].push_back(relations[i][0]);
        
        // if there are courses with no pre-requisites, set depth as 1 semester
        // else put in the set of courses to check
        for(int i=1; i <= n; ++i) {
            if(IE[i].empty()) D[i] = 1;
            else left.emplace(i);
        }
        
        int maxo = -1;
        int last_size = -1;
        // if the size of the set does not go down, the graph is not solvable, bail
        while(left.size() != last_size && !left.empty()) {
            last_size = left.size();
            unordered_set<int> leftc;
            
            for(auto it : left) {
                
                // we need to have every prerequisite course depth to determine the current depth
                bool complete = true;
                int m = 0; // maximum depth of all prerequisites
                for(int i=0; i < IE[it].size(); ++i) {
                    int e = IE[it][i];
                    if(D[e] == 0) {
                        complete = false;
                        break;
                    }
                    
                    if(D[e] > m) m = D[e];
                }
                
                // if the course is solved, update the depth, remove from set
                if(complete) {
                    D[it] = m + 1;
                    if(D[it] > maxo) maxo = D[it];    
                } else 
                    leftc.emplace(it);
            }
            left = leftc;
        }
        
        return last_size == left.size()?-1:maxo;
    }
};
class Solution {
public:
    // [[5,10],[6,8],[1,5],[2,3],[1,10]]
    // [1,5], [1,10], [2,3], [5,10], [6,8] <-- sort
    
    // [1,5] -> [6,8]
    // [1,10] 
    // [2,3] -> [5,10]
    
    
    int minGroups(vector<vector<int>>& intervals) {
        printf("size of intervales = %d\n", intervals.size());
        sort(intervals.begin(), intervals.end(), [](auto&lhs, auto&rhs){
           return lhs[0] < rhs[0];
        });
        
        int ans = 0;
        int n = intervals.size();
        unordered_set<int> s;//i in set iff i have already in one group. 
        for(int i = 0; i < n;i++) {
            if(s.find(i) != s.end()) continue;
            s.insert(i);
            int end = intervals[i][1];
            ans++;
            for(int j = i+1; j<n;j++) {
                if(s.find(j) != s.end()) continue;
                if(intervals[j][0] > end) { 
                    s.insert(j);
                    end = intervals[j][1];
                }
            }
        }
        return ans;        
    }
};

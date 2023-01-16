class Solution {
    //https://leetcode.com/problems/insert-interval
    //article https://leetcode.com/problems/insert-interval/discuss/3056773/C%2B%2B-O(N)
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int start = newInterval[0];
        int end = newInterval[1];
        for(int i = 0; i<n; i++) {
            if(intervals[i][0]<=start && start<=intervals[i][1]) 
                start = intervals[i][0];
            if(intervals[i][0]<=end && end<=intervals[i][1]) 
                end = intervals[i][1];
        }
        
        printf("{start,end} = %d,%d\n",start,end);
        int i = 0;
        for(i=0;i<n;i++) {
            vector<int> & inter =intervals[i];
            if(inter[1]<start) 
                ans.push_back(inter);
            else 
                break;
        }
        ans.push_back({start,end});
        for(;i<n;i++) {
            vector<int> & inter =intervals[i];
            if(inter[0]>end) {
                ans.push_back(inter);
            } 
        }
        
        
        return ans;
    }
};
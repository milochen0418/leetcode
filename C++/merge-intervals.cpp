class Solution {
    //https://leetcode.com/problems/merge-intervals
    //article https://leetcode.com/problems/merge-intervals/discuss/3057931/C%2B%2B-Sorting-(90-faster)
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](auto &lhs, auto &rhs){
            if(lhs[0]==rhs[0])
                return lhs[1]<rhs[1];
            else 
                return lhs[0]<rhs[0];
        });
        vector<vector<int>>ans;
        int n = intervals.size();
        vector<int> add = intervals[0]; 
        for(int i = 1;i<n;i++) {
            if(intervals[i][0]<=add[1]) {
                add[1] = max(intervals[i][1],add[1]);
            } else {
                ans.push_back(add);
                add = intervals[i];
            }
        }
        ans.push_back(add);
        return ans;
    }
};
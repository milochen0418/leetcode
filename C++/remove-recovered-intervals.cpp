class Solution {
    //https://leetcode.com/problems/remove-covered-intervals
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>>& v = intervals;
        sort(v.begin(), v.end(), [](auto r, auto l){return r[0]<l[0];});
        
        int n = v.size();
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            int start =v[i][0];
            int end = v[i][1];
            int j = start;
            while(j<n && v[j][0]<=end) {
                if(v[j][1]<=end) cnt++;
                j++;
            }
        }        
        return n-cnt;
    }
};

/* test-case
[[1,4],[3,6],[2,8]]
[[1,4],[2,3]]
[[0,10],[5,12]]
*/

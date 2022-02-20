class Solution {
    //https://leetcode.com/problems/remove-covered-intervals
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>>& v = intervals;
        sort(v.begin(), v.end(), [](auto r, auto l){return r[0]!=l[0]?r[0]<l[0]:r[1]>l[1] ;});
        
        int n = v.size();
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            int start =v[i][0];
            int end = v[i][1];
            int j = i+1;
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
[[1,2],[1,4],[3,4]]
[[34335,39239],[15875,91969],[29673,66453],[53548,69161],[40618,93111]]
*/

class Solution {
    //https://leetcode.com/problems/minimum-time-visiting-all-points
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        for(int i = 1; i<n; i++) {
            auto &p2 = points[i];
            auto &p1 = points[i-1];
            ans += max(abs(p2[1] - p1[1]), abs(p2[0]-p1[0]));
        }
        return ans;
    }
};
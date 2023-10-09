class Solution {
    //https://leetcode.com/problems/largest-triangle-area
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans=0.0f;
        int n = points.size();
        for(int i = 0; i<n; i++) 
            for(int j=i+1;j<n;j++) 
                for(int k=j+1;k<n;k++) 
                    ans = max(ans, triarea(points,i,j,k));
        return ans;
    }
    double triarea(vector<vector<int>>& points,int p1, int p2, int p3) {
        vector<vector<double>> T = {
            {(double)points[p1][0],(double) points[p1][1]},
            {(double)points[p2][0],(double) points[p2][1]},
            {(double)points[p3][0],(double) points[p3][1]}
        };
        double ans=0.0f;
        for(int i=0;i<3;i++) 
            ans += T[i%3][0] * (T[(i+1)%3][1] - T[(i+2)%3][1]);
        return ans = abs(ans) * 0.5f;
    }
};
class Solution {
    //https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans = vector<int>(n,0);
        for(int i = 0; i<n; i++) {
            vector<int>& q = queries[i];
            int r2 = q[2]*q[2];
            for(auto &p: points) {
                int xdist=abs(p[0]-q[0]), ydist=abs(p[1]-q[1]);
                if(xdist*xdist + ydist*ydist <= r2) ans[i]++;
            }
        }
        return ans;
    }
};
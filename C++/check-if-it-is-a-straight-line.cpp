class Solution {
    //https://leetcode.com/problems/check-if-it-is-a-straight-line
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        vector<int>& p0 = coordinates[0];
        vector<int>& p1 = coordinates[1];
        int dx = p1[0]-p0[0];
        int dy = p1[1]-p0[1];
        int n = coordinates.size();
        if(n<=2) return true;
        for(int i=2; i<n; i++) {
            vector<int>& pi = coordinates[i];
            int dX = pi[0]-p0[0];
            int dY = pi[1]-p0[1];
            //Need to make sure dy/dx == dY/dX -> dx*dY == dX*dy
            if(dx*dY!=dX*dy) return false;
        }
        return true;
    }
};
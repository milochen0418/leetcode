class Solution {
    //https://leetcode.com/problems/valid-boomerang
public:
    bool isBoomerang(vector<vector<int>>& points) {
        vector<vector<int>>& ps = points;
        //if(ps[0]==ps[1]||ps[0]==ps[2]||ps[1]==ps[2]) return false;
        int dx1 = ps[1][0] - ps[0][0];
        int dy1 = ps[1][1] - ps[0][1];

        int dx2 = ps[2][0] - ps[0][0];
        int dy2 = ps[2][1] - ps[0][1];
        
        //printf("dy1,dx1,dy2,dx2 = %d,%d,%d,%d\n", dy1,dx1,dy2,dx2);
        return (dx1*dy2 != dx2*dy1);
        
            
    }
};
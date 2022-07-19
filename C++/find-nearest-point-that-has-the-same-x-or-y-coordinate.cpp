class Solution {
    //https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        for(int i = 0; i<points.size();i++) points[i].push_back(i);
        sort(points.begin(), points.end(), [&](auto& lhs, auto& rhs){
            int vl = abs(lhs[0]-x) + abs(lhs[1]-y);
            int vr = abs(rhs[0]-x) + abs(rhs[1]-y);
            if(vl==vr) return lhs[2]<rhs[2];
            return vl<vr;
        });
        for(auto &p:points) if(p[0]==x || p[1]==y) return p[2];
        return -1;            
    }
};
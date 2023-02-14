class Solution {
    //https://leetcode.com/problems/k-closest-points-to-origin
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](auto &lhs, auto &rhs){
            double L = lhs[0]*lhs[0] + lhs[1]*lhs[1];
            double R = rhs[0]*rhs[0] + rhs[1]*rhs[1];
            return L<R;            
        });
        vector<vector<int>> ans;
        for(int i = 0; i<k; i++) ans.push_back(points[i]);
        return ans;
    }
};
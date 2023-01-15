class Solution {
    //https://leetcode.com/problems/matrix-cells-in-distance-order
    //article https://leetcode.com/problems/matrix-cells-in-distance-order/discuss/3054652/C%2B%2B-Sorting-10-lines
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;
        for(int r=0; r<rows; r++) 
            for(int c=0; c<cols; c++) 
                ans.push_back({r,c});
        sort(ans.begin(), ans.end(), [&](auto &lhs, auto &rhs) {
            int L = abs(lhs[0]-rCenter) + abs(lhs[1]-cCenter);
            int R = abs(rhs[0]-rCenter) + abs(rhs[1]-cCenter);
            return (L==R)?lhs[0]*cols+lhs[1]<rhs[0]*cols+rhs[1]:L<R;
        });
        return ans;
    }
};
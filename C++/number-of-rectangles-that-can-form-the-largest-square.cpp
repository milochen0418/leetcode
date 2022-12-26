class Solution {
    //https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<vector<int>>& A = rectangles;
        int maxv = 0, ans = 0;
        for(auto &r: A) maxv = max(maxv, min(r[0],r[1]));
        for(auto &r: A) ans += (min(r[0],r[1])==maxv);
        return ans;
    }
};
class Solution {
    //https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(int x = left; x<=right;x++) {
            bool is_covered = false;
            for(auto &r:ranges) {
                int start = r[0], end = r[1];
                if(start<=x && x <= end) {
                    is_covered = true;
                    break;
                }
            }
            if(is_covered == false) return false;
        }   
        return true;
    }
};
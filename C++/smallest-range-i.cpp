class Solution {
    //https://leetcode.com/problems/smallest-range-i
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minv = INT_MAX, maxv = INT_MIN;
        for(auto &i: nums) {
            minv = min(minv, i);
            maxv = max(maxv, i);
        } 
        int range =  (maxv-k) - (minv+k);
        return range<0?0:range;
    }
};
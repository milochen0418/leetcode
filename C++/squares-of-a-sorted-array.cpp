class Solution {
    //https://leetcode.com/problems/squares-of-a-sorted-array/
public:
    vector<int>& sortedSquares(vector<int>& nums) {
        for(auto& num:nums) num*=num;
        sort(nums.begin(), nums.end());
        return nums;
    }
};
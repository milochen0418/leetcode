class Solution {
    //https://leetcode.com/problems/maximum-product-difference-between-two-pairs
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        return nums[0]*nums[1] - nums[n-2]*nums[n-1];
    }
};
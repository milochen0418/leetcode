class Solution {
    //https://leetcode.com/problems/running-sum-of-1d-array/
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 0; i<nums.size();i++) nums[i]+= i>0?nums[i-1]:0;
        return nums;
    }
};
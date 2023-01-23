class Solution {
    //https://leetcode.com/problems/check-if-an-array-is-consecutive
public:
    bool isConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i =1;i<nums.size();i++) {
            if(nums[i-1]+1!=nums[i]) return false;
        }
        return true;
    }
};
class Solution {
    //https://leetcode.com/problems/check-if-an-array-is-consecutive
    //article https://leetcode.com/problems/check-if-an-array-is-consecutive/discuss/3091391/C%2B%2B-SC%3A-O(1)
public:
    bool isConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i =1;i<nums.size();i++) {
            if(nums[i-1]+1!=nums[i]) return false;
        }
        return true;
    }
};
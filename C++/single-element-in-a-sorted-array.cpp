class Solution {
    //https://leetcode.com/problems/single-element-in-a-sorted-array/
public:
    int singleNonDuplicate(vector<int>& nums) {
        //[0,0,1,1,4,4,5,7, 7,8, 8,9, 9]
        // 0   2   4   8   10   12   14
        int n = nums.size();
        if(n<2) return nums[0];
        for(int i = 0; i<n; i+=2) {
            if(nums[i+1]!=nums[i]) return nums[i];
        }
        return -1;
    }
};
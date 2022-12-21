class Solution {
    //https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i = 1; i<n;i++) {
            if(nums[i]<=nums[i-1]) {
                int new_inc = (nums[i-1]+1)-nums[i];
                nums[i]+=new_inc;
                ans+=new_inc;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n;i++) 
            nums[i] = (i==0)?nums[i]:nums[i]+nums[i-1];
        return nums;
    }
};
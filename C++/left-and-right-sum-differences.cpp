class Solution {
    //https://leetcode.com/problems/left-and-right-sum-differences/
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> leftSum = {0};
        vector<int> rightSum = {0};
        int n = nums.size();
        for(int i = 0; i<n-1;i++) 
            leftSum.push_back(leftSum.back()+nums[i]);
        
        
        reverse(nums.begin(), nums.end());
        for(int i = 0; i<n-1;i++) 
            rightSum.push_back(rightSum.back()+nums[i]);        
        reverse(rightSum.begin(), rightSum.end());
        
        
        //reverse(nums.begin(), nums.end());
        for(int i = 0; i<n;i++) 
            nums[i] = abs(leftSum[i] - rightSum[i]);
        return nums;
    }
};
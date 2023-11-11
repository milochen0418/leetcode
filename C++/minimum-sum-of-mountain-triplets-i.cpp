class Solution {
    //https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        for(int i = 0; i<n; i++) 
            for(int j = i+1; j<n; j++) 
                for(int k = j+1; k<n;k++) 
                    if(nums[i]<nums[j] && nums[k]<nums[j]) 
                        ans = min(ans, nums[i]+nums[j]+nums[k]);
        return ans==INT_MAX?-1:ans;
    }
};
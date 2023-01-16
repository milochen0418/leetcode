class Solution {
    //https://leetcode.com/problems/array-partition
public:
    int arrayPairSum(vector<int>& nums) {
        int ans = 0, n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 1; i<n; i+=2) ans+=nums[i];
        return ans;          
    }
};
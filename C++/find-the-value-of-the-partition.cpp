class Solution {
    //https://leetcode.com/problems/find-the-value-of-the-partition/
public:
    int findValueOfPartition(vector<int>& nums) {
        //[1,3,2,4] -> [1,2,3,4]   
        //[100,1,10]
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 1; i<n; i++) {
            ans = min(ans, nums[i]-nums[i-1]);
        }
        return ans;
    }
};
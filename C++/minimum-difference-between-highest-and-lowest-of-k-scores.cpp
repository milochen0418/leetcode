class Solution {
    //https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX, n = nums.size();
        for(int i = 0; i+k-1<n;i++) {
            ans = min(ans, abs (nums[i+k-1] - nums[i]));
        }
        return ans;
    }
};
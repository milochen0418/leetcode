class Solution {
    //https://leetcode.com/problems/minimize-maximum-pair-sum-in-array
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=0, n = nums.size(), L=0, R=n-1;
        while(L<R) ans = max(ans, nums[L++] + nums[R--]);
        return ans;
    }
};
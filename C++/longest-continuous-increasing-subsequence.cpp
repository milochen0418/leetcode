class Solution {
    //https://leetcode.com/problems/longest-continuous-increasing-subsequence
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int L = 0, ans = 1, n = nums.size();
        for(int R = 1;R<n;R++) {
            if(nums[R]>nums[R-1]) {
                ans = max(ans, R-L+1);
            } else {
                L=R;
            }
        }
        return ans;
    }
};
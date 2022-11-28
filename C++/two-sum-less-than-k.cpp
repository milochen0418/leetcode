class Solution {
    //https://leetcode.com/problems/two-sum-less-than-k
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int ans = -1, n = nums.size();
        for(int i = 0; i<n;i++) {
            for(int j = i+1;j<n;j++) {
                int sum = nums[i] + nums[j];
                if(sum<k) ans = max(ans, sum);
            }
        }
        return ans;
    }
};
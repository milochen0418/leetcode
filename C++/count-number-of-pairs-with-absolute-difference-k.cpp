class Solution {
    //https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i<n;i++) {
            for(int j = i+1;j<n;j++) {
                ans+=(abs(nums[i]-nums[j])==k);
            }
        }
        return ans;
    }
};
class Solution {
    //https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order
    //article https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/discuss/3024669/C%2B%2B-Sorting-10-lines
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> tmp = nums, ans;
        for(int i = 1;i<n; i++) nums[i]=nums[i-1]+nums[i];
        int v = nums[n-1]/2;
        for(int i = 0;i<n; i++) {
            ans.push_back(tmp[i]);
            if(nums[i]>v)break;
        }
        return ans;
    }
};
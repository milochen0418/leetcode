class Solution {
    //https://leetcode.com/problems/sum-in-a-matrix
public:
    int matrixSum(vector<vector<int>>& nums) {
        for(auto &v:nums)
            sort(v.begin(), v.end(), [&](auto& lhs, auto& rhs){return lhs>rhs;});
        int n = nums[0].size(), m = nums.size(), ans=0;
        for(int c = 0; c<n; c++) {
            int val = 0;
            for(int r = 0; r<m; r++) 
                val = max(val, nums[r][c]);
            ans+=val;
        }
        return ans;
    }
};
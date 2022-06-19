class Solution {
    //https://leetcode.com/problems/maximum-subarray
public:
    vector<vector<int>> dp;
    int maxSubArray(vector<int>& nums) {
        int val = 0, max_val = INT_MIN;
        for(auto &i:nums) {
            val+=i;
            max_val = max(val,max_val);
            if(val<0) val = 0;
        }
        return max_val;
    }
};
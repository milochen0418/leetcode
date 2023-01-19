class Solution {
    //https://leetcode.com/problems/subarray-sums-divisible-by-k/
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //TLE
        int n = nums.size(), ans = 0;
        for(int i = 1;i<n;i++) nums[i]+=nums[i-1];
        for(int i = 0; i<n;i++) {
            for(int j =i;j<n;j++) {
                int nums_i_1 = i==0?0:nums[i-1];
                int sum_i_j = nums[j] - nums_i_1; //sum[i..j]
                if(sum_i_j%k ==0) ans++;
            }
        }
        return ans;
    }
};
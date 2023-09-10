class Solution {
    //https://leetcode.com/problems/max-pair-sum-in-an-array
public:
    int maxSum(vector<int>& nums) {
        vector<int> d;
        for(auto val: nums) {
            int maxv = 0;
            while(val>0) {
                maxv = max(maxv, val%10);
                val = val/10;
            }
            d.push_back(maxv);
        }
        int n = nums.size(), ans= -1;
        for(int i = 0;i<n; i++) 
            for(int j =i+1; j<n;j++) 
                if(d[i]==d[j]) ans=max(ans, nums[i]+nums[j]);
        return ans;
    }
};
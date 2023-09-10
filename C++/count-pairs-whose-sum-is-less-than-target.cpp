class Solution {
    //https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size(), ans=0;
        for(int i = 0; i< n; i++) 
            for(int j = i+1;j<n;j++) 
                if(nums[i]+nums[j]<target) ans++;
        return ans;
    }
};
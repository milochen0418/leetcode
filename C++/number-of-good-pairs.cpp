class Solution {
    //https://leetcode.com/problems/number-of-good-pairs
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size(),ans=0;
        for(int i = 0;i<n;i++) 
            for(int j = i+1;j<n;j++) 
                if(nums[i]==nums[j]) ans++;
        return ans;
    }
};
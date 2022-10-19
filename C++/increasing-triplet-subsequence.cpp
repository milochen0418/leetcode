class Solution {
    //https://leetcode.com/problems/increasing-triplet-subsequence
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n;i++) { 
            for(int j = i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    if(nums[i]<nums[j] && nums[j]<nums[k]) {
                        return true;
                    } 
                }
            }
        }   
        return false;
    }
};
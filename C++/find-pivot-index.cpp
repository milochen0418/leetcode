class Solution {
    //https://leetcode.com/problems/find-pivot-index
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0, total = accumulate(nums.begin(), nums.end(),0);
        for(int i = 0;i<nums.size();i++) {
            if( total-nums[i]==sum*2) return i;
            sum+=nums[i];
        }
        return -1;
    }
};
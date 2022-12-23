class Solution {
    //https://leetcode.com/problems/minimum-distance-to-the-target-element/
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        for(int i = 0;i<n;i++) {
            int minus = start-i, plus=start+i;
            if(minus>=0 && nums[minus]==target) return i;
            if(plus<n && nums[plus] == target) return i;            
        }
        return -1;
    }
};